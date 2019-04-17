public class WarnsdorffMove {
    private Move move;
    private int moveCount;

    public WarnsdorffMove(Move move, int moveCount) {
        this.move = move;
        this.moveCount = moveCount;
    }

    public Move getMove() {
        return move;
    }

    public int getMoveCount() {
        return moveCount;
    }

    @Override
    public String toString() {
        return "(" + move.getX() + ", " + move.getY() + ") with " + moveCount + " available moves from that point.";
    }
}
