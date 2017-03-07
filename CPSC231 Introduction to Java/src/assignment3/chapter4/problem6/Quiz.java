package assignment3.chapter4.problem6;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Quiz {
    private final int MAX_SCORE = 10;
    private int score;

    public Quiz(int quiz1) {
        score = quiz1;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
