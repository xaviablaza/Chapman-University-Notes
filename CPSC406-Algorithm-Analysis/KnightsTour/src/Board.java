public class Board {
    private int[][] board;
    private int size;
    int numPositions;

    // Number of locations visited
    private int visited = 0;

    public Board(int size) {
        this.board = new int[size][size];
        this.size = size;
        numPositions = size * size;
        generate();
    }

    /**
     * Visit a location on the board
     * @param x
     * @param y
     */
    public void visit(int x, int y) {
        if (board[y][x] == 1) {
            System.out.println("The value: " + x + ", " + y + " has already been visited.");
        } else {
            board[y][x] = 1;
            visited += 1;
        }
    }

    /**
     * Unvisit a location on the board
     * @param x
     * @param y
     */
    public void unvisit(int x, int y) {
        board[y][x] = -1;
        visited -= 1;
    }

    /**
     * Checks if a location has been visited
     * @param x
     * @param y
     */
    public boolean beenVisited(int x, int y) {
        return board[y][x] == 1;
    }

    /**
     * Fills the board with -1 given the input size
     */
    private void generate() {
        for (int x=0; x<size; ++x) {
            for (int y=0; y<size; ++y) {
                board[y][x] = -1;
            }
        }
    }

    /**
     * Board is complete if all positions are visited
     * @return true if all positions on the board are visited
     */
    public boolean isComplete() {
        return visited == numPositions;
    }

    public void display() {
        System.out.println(" ======= Board Info ======");
        for (int x=0; x<size; ++x) {
            for (int y=0; y<size; ++y) {
                if (board[x][y] == 1) {
                    System.out.print("X");
                } else {
                    System.out.print("O");
                }
            }
            System.out.println();
        }
        System.out.println(" =========================");
    }

}
