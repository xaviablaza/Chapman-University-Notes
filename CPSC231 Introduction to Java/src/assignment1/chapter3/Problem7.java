package assignment1.chapter3;

import java.util.Scanner;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Enter a value: ");
            double x = scanner.nextDouble();
            double sum = 1;
            double f = 1;
            for (int i=1; i<101; ++i) {
                f *= i;
                sum += Math.pow(x, i)/f;
                switch (i) {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 50:
                    case 100:
                        System.out.println("n = " + i + ", sum = " + sum);
                }
            }
            System.out.println("Type 'exit' to exit, otherwise you will be prompted to enter another value: ");
            String input = scanner.next();
            if (input.equalsIgnoreCase("exit")) break;
        }
    }
}
