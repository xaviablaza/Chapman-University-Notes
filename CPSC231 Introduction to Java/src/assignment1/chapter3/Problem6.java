package assignment1.chapter3;

import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the initial size of a green crud population in pounds: ");
        int p1 = 0;
        int p2 = Integer.valueOf(scanner.nextLine());
        int p3 = p2;
        int day = 1;
        boolean exit = false;
        while (!exit) {
            if (day % 5 == 0) {
                p3 = p1+p2;
                p1 = p2;
                p2 = p3;
            }
            System.out.println("Day " + day + ": " + p3 + " pounds");
            day++;
            System.out.println("Press enter to continue or type 'exit' to exit.");
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) exit = true;
        }

    }
}
