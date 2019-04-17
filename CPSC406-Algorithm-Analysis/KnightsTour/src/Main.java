
public class Main {

    public static void main(String[] args) {
        String boardSize = args[0];
        String startPositionX = args[1];
        String startPositionY = args[2];
        String isHeuristic = "";
        if (args.length == 4) {
            isHeuristic = args[3];
        }
        KnightsTour kTour = new KnightsTour(boardSize, startPositionX, startPositionY, isHeuristic);
        kTour.solve();
    }
}
