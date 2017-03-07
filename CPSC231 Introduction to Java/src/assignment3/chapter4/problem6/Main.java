package assignment3.chapter4.problem6;

import java.util.Scanner;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the score for the first quiz (0-10):");
        int quiz1 = scanner.nextInt();
        System.out.println("Enter the score for the second quiz (0-10):");
        int quiz2 = scanner.nextInt();
        System.out.println("Enter the score for the third quiz (0-10):");
        int quiz3 = scanner.nextInt();
        System.out.println("Enter the score for the midterm exam (0-100):");
        int midterm = scanner.nextInt();
        System.out.println("Enter the score for the final exam (0-100):");
        int finalExam = scanner.nextInt();
        StudentRecord studentRecord = new StudentRecord(quiz1, quiz2, quiz3, midterm, finalExam);
        studentRecord.calculateOverallScore();
        studentRecord.calculateLetterGrade();
        System.out.println(studentRecord.toString());
    }
}
