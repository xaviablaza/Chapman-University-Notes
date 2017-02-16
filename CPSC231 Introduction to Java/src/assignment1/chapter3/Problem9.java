package assignment1.chapter3;

import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("How many exercises to input?");
        int numExercises = scanner.nextInt();
        int score = 0;
        int pointsPossible = 0;
        for (int i=1; i<numExercises+1; ++i) {
            System.out.println("Score received for exercise " + i + ":");
            score += scanner.nextInt();
            System.out.println("Total points possible for exercise " + i + ":");
            pointsPossible += scanner.nextInt();
        }
        DecimalFormat df = new DecimalFormat("##.##");
        System.out.println("Your total is " + score + " out of " + pointsPossible + ", or " + df.format((double)score/pointsPossible*100) + "%");
    }
}
