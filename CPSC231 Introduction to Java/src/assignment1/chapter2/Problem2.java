package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your first name: ");
        String first = scanner.next().toLowerCase();
        System.out.print("Enter your last name: ");
        String last = scanner.next().toLowerCase();
        String pigLatin = first.substring(1, 2).toUpperCase() + first.substring(2) + first.substring(0, 1) + "ay" + " " + last.substring(1, 2).toUpperCase() + last.substring(2) + last.substring(0, 1) + "ay";
        System.out.println(pigLatin);
    }
}
