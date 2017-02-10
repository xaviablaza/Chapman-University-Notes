package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter purchase price of an item: ");
        double price = scanner.nextDouble();
        System.out.print("Enter expected number of years of service: ");
        int years = scanner.nextInt();
        System.out.print("Enter expected salvage value: ");
        double salvage = scanner.nextDouble();
        double annualDep = (price-salvage)/years;
        System.out.println("The yearly depreciation for the item is $" + annualDep);
    }
}
