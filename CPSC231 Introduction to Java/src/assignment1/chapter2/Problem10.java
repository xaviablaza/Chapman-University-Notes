package assignment1.chapter2;

import java.util.Scanner;

/**
 * Created by Xavi on 2/9/2017.
 */
public class Problem10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Input name of item 1:");
        String i1 = scanner.nextLine();
        i1 = i1.trim();
        System.out.println("Input quantity of item 1:");
        int q1 = Integer.valueOf(scanner.nextLine());
        System.out.println("Input price of item 1:");
        double p1 = Double.valueOf(scanner.nextLine());


        System.out.println("Input name of item 2:");
        String i2 = scanner.nextLine();
        i2 = i2.trim();
        System.out.println("Input quantity of item 2:");
        int q2 = Integer.valueOf(scanner.nextLine());
        System.out.println("Input price of item 2:");
        double p2 = Double.valueOf(scanner.nextLine());

        System.out.println("Input name of item 3:");
        String i3 = scanner.nextLine();
        i3 = i3.trim();
        System.out.println("Input quantity of item 3:");
        int q3 = Integer.valueOf(scanner.nextLine());
        System.out.println("Input price of item 3:");
        double p3 = Double.valueOf(scanner.nextLine());

        String[] items = {i1, i2, i3};
        int[] quantities = {q1, q2, q3};
        double[] prices = {p1, p2, p3};

        System.out.println("Your bill:");
        System.out.println();
        System.out.println("Item                          Quantity  Price     Total     ");
        double subTotal = 0.0;

        for (int j=0; j<3; ++j) {
            System.out.print(items[j]);
            for (int i=0; i<30-items[j].length(); ++i) {
                System.out.print(" ");
            }
            System.out.print(quantities[j]);
            for (int i=0; i<10-String.valueOf(quantities[j]).length(); ++i) {
                System.out.print(" ");
            }
            System.out.print(prices[j]);
            for (int i=0; i<10-String.valueOf(prices[j]).length(); ++i) {
                System.out.print(" ");
            }
            double total = quantities[j] * prices[j];
            subTotal += total;
            System.out.print(total);
            System.out.print('\n');
        }

        double salesTax = subTotal * 0.0625;
        System.out.println("Subtotal                                          " + salesTax);
        subTotal += salesTax;
        System.out.println("Total                                             " + subTotal);


    }
}
