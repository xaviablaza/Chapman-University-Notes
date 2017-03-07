package assignment3.chapter4.problem6;

/**
 * Created by Xavi on 3/6/2017.
 */
public class MidtermExam {
    private final int MAX_SCORE = 10;
    private int score;

    public MidtermExam(int midterm) {
        score = midterm;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
