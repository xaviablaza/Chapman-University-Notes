package assignment1.chapter3;

import java.util.Random;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem11 {
    public static void main(String[] args) {
        Random r = new Random();
        int finalist1 = r.nextInt(30)+1;
        int finalist2, finalist3;
        do {
            finalist2 = r.nextInt(30)+1;
        } while (finalist1 == finalist2);
        do {
            finalist3 = r.nextInt(30)+1;
        } while (finalist1 == finalist3 || finalist2 == finalist3);
        System.out.println("You decide to give away the prizes to finalist numbers: " + finalist1 + ", " + finalist2 + ", and " + finalist3);
    }
}
