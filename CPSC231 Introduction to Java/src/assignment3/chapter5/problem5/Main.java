package assignment3.chapter5.problem5;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Main {
    public static void main(String[] args) {
        Money m1 = new Money(1, 50);
        Money m2 = new Money(1, 300);
        m1.add(m2);
        System.out.println(m1);
    }
}
