package assignment3.chapter5.problem6;

/**
 * Created by Xavi on 3/7/2017.
 */
public class Main {
    public static void main(String[] args) {
        Rational r1 = new Rational(1, 2);
        Rational r2 = new Rational(1, -4);
        System.out.println(Rational.add(r1, r2).toString());
        System.out.println(Rational.minus(r1, r2).toString());
        System.out.println(Rational.multiply(r1, r2).toString());
        System.out.println(Rational.divide(r1, r2).toString());
    }
}
