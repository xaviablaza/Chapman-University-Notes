package assignment3.chapter5.problem5;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Money {
    private int dollars;
    private int cents;

    public Money() {
        this.dollars = 0;
        this.cents = 0;
    }

    public Money(int dollars) {
        this.dollars = dollars;
        this.cents = 0;
    }

    public Money(int dollars, int cents) {
        this.dollars = dollars;
        this.cents = cents;
    }

    public int getDollars() {
        return dollars;
    }

    public void setDollars(int dollars) {
        this.dollars = dollars;
    }

    public int getCents() {
        return cents;
    }

    public void setCents(int cents) {
        if (cents >= 100) {
            dollars += cents/100;
            cents = cents % 100;
        } else if (cents < 0) {
            cents = 0;
        } else {
            this.cents = cents;
        }
    }

    public void add(Money m) {
        dollars+=m.getDollars();
        cents+=m.getCents();
        dollars += cents/100;
        cents = cents % 100;
    }

    public void minus(Money m) {
        dollars-=m.getDollars();
        cents-=m.getCents();
        if (cents < 0) {
            dollars-=1;
            cents*=-1;
        }
    }

    public static Money add(Money m1, Money m2) {
        return new Money(m1.getDollars()+m2.getDollars(), m1.getCents()+m2.getCents());
    }

    public static Money minus(Money m1, Money m2) {
        return new Money(m1.getDollars()-m2.getDollars(), m1.getCents()-m2.getCents());
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Money) {
            Money money = (Money)obj;
            return (this.dollars == money.getDollars() && this.cents == money.getCents());
        } else return false;
    }

    @Override
    public String toString() {
        return "$"+dollars+"."+cents;
    }
}
