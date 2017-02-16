package assignment1.chapter3;

import java.util.Random;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem2 {
    public static void main(String[] args) {
        Random r = new Random();
        int win = 0;
        int loss = 0;
        for (int i=0; i<10000; ++i) {
            int dice1 = r.nextInt(6)+1;
            int dice2 = r.nextInt(6)+1;
            int point = dice1+dice2;
            if (point == 7 || point == 11) win++;
            else if (point == 2 || point == 3 || point == 12) loss++;
            else {
                while (true) {
                    int sum = r.nextInt(6)+1 + r.nextInt(6)+1;
                    if (sum == point) {
                        win++;
                        break;
                    } else if (sum == 7) {
                        loss++;
                        break;
                    }
                }
            }
        }
        double chance = (double)win/(win+loss);
        System.out.println("Probability of winning: " + chance);
        System.out.println("In the long run, the house will win more games.");
    }
}
