import java.util.Comparator;

public class WarnsdorffMoveComparator implements Comparator<WarnsdorffMove> {
    @Override
    public int compare(WarnsdorffMove o1, WarnsdorffMove o2) {
        if (o1.getMoveCount() < o2.getMoveCount()) {
            return -1;
        }
        if (o1.getMoveCount() > o2.getMoveCount()) {
            return 1;
        }
        return 0;
    }
}
