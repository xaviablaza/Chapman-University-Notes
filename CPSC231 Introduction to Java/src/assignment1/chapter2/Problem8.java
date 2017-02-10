package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a line of text: ");
        String line = scanner.next();
        System.out.println("Here's the line of text in all uppercase:");
        System.out.println(line.toUpperCase());
        System.out.println("Here's the line of text in all lowercase:");
        System.out.println(line.toLowerCase());
    }
}
