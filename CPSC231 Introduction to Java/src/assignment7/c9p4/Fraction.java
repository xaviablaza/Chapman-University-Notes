package assignment7.c9p4;

/**
 * Created by Xavi on 4/29/2017.
 */
public class Fraction {
    private int numerator;
    private int denomiator;

    public Fraction(int numerator, int denomiator) throws DenominatorIsZeroException {
        this.numerator = numerator;
        if (denomiator == 0) throw new DenominatorIsZeroException();
        this.denomiator = denomiator;
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenomiator() {
        return denomiator;
    }

    public void setDenomiator(int denomiator) throws DenominatorIsZeroException {
        if (denomiator == 0) throw new DenominatorIsZeroException();
        this.denomiator = denomiator;
    }
}
