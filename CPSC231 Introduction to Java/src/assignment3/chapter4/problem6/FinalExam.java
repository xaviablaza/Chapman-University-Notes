package assignment3.chapter4.problem6;

/**
 * Created by Xavi on 3/6/2017.
 */
public class FinalExam {
    private final int MAX_SCORE = 100;
    private int score;

    public FinalExam(int finalExam) {
        score = finalExam;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
