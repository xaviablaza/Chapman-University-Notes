package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first integer: ");
        int a = scanner.nextInt();
        System.out.print("Enter the second integer: ");
        int b = scanner.nextInt();
        System.out.println("Sum: " + (a+b));
        System.out.println("Difference: " + (a-b));
        System.out.println("Product: " + (a*b));
    }
}
