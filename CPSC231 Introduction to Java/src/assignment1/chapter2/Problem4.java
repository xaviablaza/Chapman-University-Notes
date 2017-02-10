package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter commute distance: ");
        double commuteDistance = scanner.nextDouble();
        System.out.print("Enter fuel consumption rate: ");
        double consumptionRate = scanner.nextDouble();
        System.out.print("Enter price of a gallon of gas: ");
        double gasPrice = scanner.nextDouble();
        double cost = commuteDistance / consumptionRate * gasPrice;
        System.out.println("The cost of your commute is $" + cost);
    }
}
