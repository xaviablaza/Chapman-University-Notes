import java.util.*;

public class KnightsTour {
    // The board size - creates a square board
    private int boardSize;

    // The starting coordinates given by command line argument
    private int startPositionX;
    private int startPositionY;

    // The current position of the knight
    private int currentPosX;
    private int currentPosY;

    // true if using Warnsdorff heuristic to calculate Knight's tour
    private boolean isHeuristic;

    private Board board;

    public KnightsTour(String boardSize, String startPositionX, String startPositionY, String isHeuristic) {
        this.boardSize = Integer.valueOf(boardSize);
        this.startPositionX = Integer.valueOf(startPositionX);
        this.startPositionY = Integer.valueOf(startPositionY);
        this.isHeuristic = isHeuristic.equalsIgnoreCase("--h");

        // Initialize the board
        board = new Board(this.boardSize);
    }

    public void solve() {
        // Set the current position equal to the start position
        currentPosX = startPositionX;
        currentPosY = startPositionY;

        if (isHeuristic) warnsdorff();
        else bruteForce();

    }

    private void warnsdorff() {
        int x = currentPosX;
        int y = currentPosY;
        Move move;
        for (int i=0; i<board.numPositions; ++i) {
            System.out.println("| Tour (Warnsdorff): The current position: (" + currentPosX + ", " + currentPosY + ")");
            board.display();
            x = currentPosX;
            y = currentPosY;
            // choose best next move (the move that has constrained number of next moves)
            move = chooseMove(x, y);
            x = move.getX();
            y = move.getY();
            board.visit(x, y);
            currentPosX = move.getX();
            currentPosY = move.getY();
            if (board.isComplete()) break;
            board.display();
        }
    }

    /**
     * Pick a move based on Warnsdorff rule
     * @param x
     * @param y
     */
    private Move chooseMove(int x, int y) {
        // Find the possibleMoves from the position
        List<Move> possibleMoves = findMoves(x, y);

        // Initialize priority queue to sort moves
        PriorityQueue<WarnsdorffMove> queue = new PriorityQueue<WarnsdorffMove>(possibleMoves.size(), new WarnsdorffMoveComparator());

        // Calculate the number of possible moves for each move
        for (Move move : possibleMoves) {
            int moveCount = findMoves(move.getX(), move.getY()).size();
            queue.add(new WarnsdorffMove(move, moveCount));
        }

        WarnsdorffMove wmove = queue.poll();
        System.out.println("| Tour (Warnsdorff): The next move calculated was " +
                wmove.toString());
        return wmove.getMove();
    }

    private void bruteForce() {
        // Initialize a new Stack
        Stack<Space> stack = new Stack<>();
        Space space = new Space(currentPosX, currentPosY);
        stack.push(space);

        board.display();

        int x, y;
        while (!board.isComplete()) {
            List<Move> moves = new LinkedList<>();

            // find valid moves
            x = space.getX();
            y = space.getY();
            List<Move> availableMoves = findMoves(x, y);

            // insert moves that have not failed
            for (Move move : availableMoves) {
                if (!space.getFailures().contains(move)) {
                    moves.add(move);
                }
            }

            // if there are available moves
            if (!moves.isEmpty()) {
                // try a move
                Move nextMove = moves.get(0);
                // visit the next move
                x = nextMove.getX();
                y = nextMove.getY();
                board.visit(x, y);
                // push the old value to the stack
                stack.push(space);
                // create a new space
                space = new Space(nextMove);
                // set the new current position
                currentPosX = nextMove.getX();
                currentPosY = nextMove.getY();
            } else {
                space = stack.pop();
                space.getFailures().add(new Move(currentPosX, currentPosY));
                currentPosX = space.getX();
                currentPosY = space.getY();
            }
            System.out.println("| Tour (brute-force): The current position: (" + currentPosX + ", " + currentPosY + ")");
            board.display();
        }
    }


    /**
     * Find positions in which the knight is allowed to move
     * @param x
     * @param y
     * @return
     */
    public List<Move> findMoves(int x, int y) {
        List<Move> moves = new LinkedList<Move>();
        moves.add(new Move(x+1, y+2));
        moves.add(new Move(x+1, y-2));
        moves.add(new Move(x+2, y+1));
        moves.add(new Move(x+2, y-1));
        moves.add(new Move(x-1, y+2));
        moves.add(new Move(x-1, y-2));
        moves.add(new Move(x-2, y+1));
        moves.add(new Move(x-2, y-1));

        List<Move> possibleMoves = new LinkedList<Move>();
        for (Move move : moves) {
            if (validMove(move)) possibleMoves.add(move);
        }

        List<Move> validMoves = new LinkedList<Move>();
        for (Move move : possibleMoves) {
            if (!board.beenVisited(move.getX(), move.getY())) {
                validMoves.add(move);
            }
        }

        return validMoves;
    }

    /**
     * Determine if the move is within the board
     * @param move
     * @return
     */
    private boolean validMove(Move move) {
        int x = move.getX();
        int y = move.getY();
        int sizeX = boardSize;
        int sizeY = boardSize;
        return (!(x<0) && !(x>sizeX-1) && !(y<0) && !(y>sizeY-1));
    }
}
