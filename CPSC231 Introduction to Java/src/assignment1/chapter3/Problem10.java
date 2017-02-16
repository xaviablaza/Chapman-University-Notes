package assignment1.chapter3;

import java.util.Random;
import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random r = new Random();
        System.out.println("Welcome to my cool dice game, Pig.");
        System.out.println("You will roll first.\n");
        boolean playerTurn = true;
        int humanScore = 0;
        int compScore = 0;
        int sum = 0;
        while (true) {
            int roll = r.nextInt(6)+1;
            String playerName;
            if (playerTurn) playerName = "YOU";
            else playerName = "COMPUTER";
            System.out.println(playerName + " rolled a: " + roll);
            switch (roll) {
                case 1:
                    System.out.println("No new points awarded for " + playerName + "\n");
                    System.out.println("YOUR SCORE: " + humanScore);
                    System.out.println("COMPUTER'S SCORE: " + compScore + "\n");
                    playerTurn = !playerTurn;
                    sum = 0;
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    sum += roll;
                    if (playerTurn) {
                        System.out.println("Enter 'r' to roll again or 'h' to hold:");
                        String response = scanner.next();
                        if (response.equalsIgnoreCase("r")) {
                        } else if (response.equalsIgnoreCase("h")) {
                            System.out.println();
                            humanScore += sum;
                            System.out.println("YOUR SCORE: " + humanScore);
                            System.out.println("COMPUTER'S SCORE: " + compScore + "\n");
                            playerTurn = !playerTurn;
                            sum = 0;
                        } else {
                            System.out.println("Input not valid. Try again:");
                        }
                    } else {
                        if (sum <= 20) {
                            System.out.println("COMPUTER DECIDES TO ROLL AGAIN");
                        } else {
                            compScore += sum;
                            System.out.println("COMPUTER DECIDES TO HOLD\n");
                            System.out.println("YOUR SCORE: " + humanScore);
                            System.out.println("COMPUTER'S SCORE: " + compScore + "\n");
                            playerTurn = !playerTurn;
                            sum = 0;
                        }
                    }
            }

            if (humanScore >= 100) {
                System.out.println("YOU won!");
                break;
            } else if (compScore >= 100) {
                System.out.println("THE COMPUTER won!");
                break;
            }
        }

    }
}
