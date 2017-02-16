package assignment1.chapter3;

import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input a double: ");
        double n = scanner.nextDouble();
        double guess = n/2;
        double lastGuess;
        double diff;
        do {
            lastGuess = guess;
            double r = n/guess;
            guess = (guess + r) / 2;
            diff = (lastGuess-guess)/lastGuess;
        } while (diff >= .01);
        System.out.println(Math.round(guess*100.0)/100.0);
    }
}
