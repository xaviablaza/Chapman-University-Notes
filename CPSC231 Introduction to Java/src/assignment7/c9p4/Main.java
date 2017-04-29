package assignment7.c9p4;

/**
 * Created by Xavi on 4/29/2017.
 */
public class Main {
    public static void main(String[] args) {
        try {
            Fraction fraction = new Fraction(1, 0);
        } catch (DenominatorIsZeroException e) {
            e.printStackTrace();
        }
    }
}
