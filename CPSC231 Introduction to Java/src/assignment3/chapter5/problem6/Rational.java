package assignment3.chapter5.problem6;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Rational {
    private int numerator;
    private int denominator;

    public Rational() {
        this.numerator = 0;
        this.denominator = 1;
    }

    public Rational(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
        normalize();
    }

    public Rational(int wholeNumber) {
        this.numerator = wholeNumber;
        this.denominator = 1;
    }

    public void add(Rational r) {
        int lcm = lcm(denominator, r.denominator);
        numerator = (lcm/denominator*numerator)+(lcm/r.denominator*r.numerator);
        denominator = lcm;
    }

    public void minus(Rational r) {
        int lcm = lcm(denominator, r.denominator);
        numerator = (lcm/denominator*numerator)-(lcm/r.denominator*r.numerator);
        denominator = lcm;
    }

    public void multiply(Rational r) {
        numerator*=r.numerator;
        denominator*=r.denominator;
        normalize();
    }

    public void divide(Rational r) {
        numerator*=r.denominator;
        denominator*=r.numerator;
        normalize();
    }

    public static Rational add(Rational r1, Rational r2) {
        int lcm = lcm(r1.denominator, r2.denominator);
        return new Rational((lcm/r1.denominator*r1.numerator)+(lcm/r2.denominator*r2.numerator), lcm);
    }

    public static Rational minus(Rational r1, Rational r2) {
        int lcm = lcm(r1.denominator, r2.denominator);
        return new Rational((lcm/r1.denominator*r1.numerator)-(lcm/r2.denominator*r2.numerator), lcm);
    }

    public static Rational multiply(Rational r1, Rational r2) {
        Rational r = new Rational(r1.numerator*r2.numerator, r1.denominator*r2.denominator);
        r.normalize();
        return r;
    }

    public static Rational divide(Rational r1, Rational r2) {
        Rational r = new Rational(r1.numerator*r2.denominator, r1.denominator*r2.numerator);
        r.normalize();
        return r;
    }

    static int lcm(int x, int y) {
        int a;
        a = (x > y) ? x : y;
        while (true) {
            if (a % x == 0 && a % y == 0) return a;
            ++a;
        }
    }

    public void normalize() {
        if (denominator < 0) {
            denominator*=-1;
            numerator*=-1;
        }
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        this.denominator = denominator;
        normalize();
    }

    @Override
    public String toString() {
        return numerator+"/"+denominator;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Rational) {
            Rational r = (Rational)obj;
            return (numerator*r.getDenominator() == r.getNumerator()*denominator);
        } else return false;
    }
}
