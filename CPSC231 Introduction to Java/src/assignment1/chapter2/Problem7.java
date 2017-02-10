package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter price of item");
        System.out.println("(from 25 cents to a dollar, in 5-cent increments:");
        int cents = scanner.nextInt();
        System.out.println("You bought an item for " + cents + " cents and gave me a dollar, so your change is");
        int change = 100-cents;
        int quarters = change/25;
        change-=quarters*25;
        int dimes = change/10;
        change-=dimes*10;
        int nickels = change/5;
        System.out.println(quarters + " quarters, " + dimes + " dimes, and " + nickels + " nickels.");
    }
}
