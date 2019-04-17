import java.util.HashSet;
import java.util.Set;

public class Space {
    private Move move;
    private Set<Move> failures = new HashSet<>();
    public Space(int x, int y) {
        this.move = new Move(x, y);
    }

    public Space(Move move) {
        this.move = move;
    }

    public int getX() {
        return move.getX();
    }

    public int getY() {
        return move.getY();
    }

    public Set<Move> getFailures() {
        return failures;
    }
}
