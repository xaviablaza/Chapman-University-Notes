package assignment3.chapter5.problem8;

import assignment3.chapter4.problem11.Pizza;

/**
 * Created by Xavi on 3/7/2017.
 */
public class Main {
    public static void main(String[] args) {
        Pizza pizza1 = new Pizza("large", 1, 0, 1);
        Pizza pizza2 = new Pizza("medium", 2, 2, 0);
        PizzaOrder order1 = new PizzaOrder();
        order1.setNumPizzas(2);
        order1.setPizza1(pizza1);
        order1.setPizza2(pizza2);
        double total = order1.calcTotal();
        System.out.println(total);
        PizzaOrder order2 = new PizzaOrder(order1);
        order2.getPizza1().setNumCheeseToppings(3);
        total = order2.calcTotal();
        System.out.println(total);
        double origTotal = order1.calcTotal();
        System.out.println(origTotal);
    }
}
