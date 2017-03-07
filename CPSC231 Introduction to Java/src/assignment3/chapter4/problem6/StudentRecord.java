package assignment3.chapter4.problem6;

/**
 * Created by Xavi on 3/6/2017.
 */
public class StudentRecord {
    private Quiz[] quizzes;
    private MidtermExam midtermExam;
    private FinalExam finalExam;
    private double overallScore;
    private String letterGrade;

    public StudentRecord(int quiz1, int quiz2, int quiz3, int midterm, int finalExam) {
        quizzes = new Quiz[3];
        quizzes[0] = new Quiz(quiz1);
        quizzes[1] = new Quiz(quiz2);
        quizzes[2] = new Quiz(quiz3);
        midtermExam = new MidtermExam(midterm);
        this.finalExam = new FinalExam(finalExam);
    }

    public void calculateOverallScore() {
        double quizScore = 0.0;
        for (Quiz quiz : quizzes) {
            quizScore += quiz.getScore();
        }
        quizScore = ((double)25/30)*quizScore;
        double midtermScore = 0.35*midtermExam.getScore();
        double finalScore = 0.4*finalExam.getScore();
        overallScore = quizScore+midtermScore+finalScore;
    }

    public void calculateLetterGrade() {
        if (overallScore >= 90) letterGrade = "A";
        else if (overallScore >= 80) letterGrade = "B";
        else if (overallScore >= 70) letterGrade = "C";
        else if (overallScore >= 60) letterGrade = "D";
        else if (overallScore < 60) letterGrade = "F";
    }

    @Override
    public String toString() {
        return "The student got a " + quizzes[0].getScore() + " on Quiz 1, a " + quizzes[1].getScore() + " on Quiz 2, a " +
                quizzes[2].getScore() + " on Quiz 3, a " + midtermExam.getScore() + " on the Midterm Exam, and a " + finalExam.getScore() +
                " on the Final Exam. The overall numeric score is " + overallScore + " with a letter grade of " + letterGrade + ".";
    }
}
