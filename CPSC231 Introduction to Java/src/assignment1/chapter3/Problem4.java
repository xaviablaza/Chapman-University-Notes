package assignment1.chapter3;

import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter cost of item: ");
        double itemCost = scanner.nextDouble();
        System.out.println("Enter how many years from now that the item will be purchased: ");
        int numYears = scanner.nextInt();
        System.out.println("Enter the rate of inflation (in percent): ");
        double inflationRate = scanner.nextDouble();
        inflationRate /= 100;
        for (int i=0; i<numYears; ++i) {
            itemCost += itemCost*inflationRate;
        }
        System.out.println("The price of the item after " + numYears + " years will be: " + itemCost);
    }
}
