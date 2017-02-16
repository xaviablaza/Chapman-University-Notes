package assignment1.chapter3;

import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter gender of child (M/F): ");
            String gender = scanner.next();
            boolean male = true;
            if (gender.equalsIgnoreCase("f")) male = false;
            System.out.println("Enter mother's height (feet): ");
            int motherHeight = scanner.nextInt()*12;
            System.out.println("Enter mother's height (inches): ");
            motherHeight += scanner.nextInt();
            System.out.println("Enter father's height (feet): ");
            int fatherHeight = scanner.nextInt()*12;
            System.out.println("Enter father's height (inches): ");
            fatherHeight += scanner.nextInt();
            double childHeight;
            if (male) {
                childHeight = ((motherHeight * 13/12) + fatherHeight)/2;
            } else {
                childHeight = ((fatherHeight * 12/13) + motherHeight)/2;
            }
            System.out.println("The estimated adult height of the child is: " + childHeight + " inches");
            System.out.println("Would you like to exit (y/n): ");
            String exit = scanner.next();
            if (exit.equalsIgnoreCase("y")) break;
        }

    }
}
