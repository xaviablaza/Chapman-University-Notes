package assignment4.problem15;

import assignment3.chapter4.problem11.Pizza;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Main {
    public static void main(String[] args) {
        Pizza pizza1 = new Pizza("large", 1, 0, 1);
        Pizza pizza2 = new Pizza("medium", 2, 2, 0);
        PizzaOrder order = new PizzaOrder(2);
        order.setPizza(0, pizza1);
        order.setPizza(1, pizza2);
        System.out.println(order.calcTotal());
    }
}
