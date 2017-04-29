package assignment7.c9p5;

import java.util.Scanner;

/**
 * Created by Xavi on 4/29/2017.
 */
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int month;
        int day;
        int year;
        while (true) {
            System.out.println("Enter a month (1-12): ");
            try {
                month = in.nextInt();
                if (month < 1 || month > 12) throw new MonthException();
                else break;
            } catch (MonthException e) {
                System.out.println("Month not recognized");
            }
        }
        while (true) {
            System.out.println("Enter a day (1-31): ");
            try {
                day = in.nextInt();
                int highInput = 0;
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) highInput = 31;
                else if (month == 4 || month == 6 || month == 9 || month == 11) highInput = 30;
                if (day < 1 || day > highInput) throw new DayException();
                else break;
            } catch (DayException e) {
                System.out.println("Day not recognized");
            }
        }
        while (true) {
            System.out.println("Enter a year (1000-3000): ");
            try {
                year = in.nextInt();
                if (year < 1000 || year > 3000) throw new YearException();
                else break;
            } catch (YearException e) {
                System.out.println("Year not recognized");
            }
        }
        switch (month) {
            case 1:
                System.out.print("January ");
                break;
            case 2: System.out.print("February ");
            break;
            case 3: System.out.println("March ");
            break;
            case 4: System.out.println("April ");
            break;
            case 5: System.out.println("May ");
            break;
            case 6: System.out.println("June ");
            break;
            case 7: System.out.println("July ");
            break;
            case 8: System.out.println("August ");
            break;
            case 9: System.out.println("September ");
            break;
            case 10: System.out.println("October ");
            break;
            case 11:System.out.println("November ");
            break;
            case 12:System.out.println("December ");
        }
        System.out.print(day + ", " + year);
    }
}
