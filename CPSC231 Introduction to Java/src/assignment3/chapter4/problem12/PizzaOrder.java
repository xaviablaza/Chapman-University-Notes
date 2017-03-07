package assignment3.chapter4.problem12;

import assignment3.chapter4.problem11.Pizza;

/**
 * Created by Xavi on 3/6/2017.
 */
public class PizzaOrder {
    private Pizza[] pizzas;

    public PizzaOrder(int numPizzas) {
        setNumPizzas(numPizzas);
    }

    public void setNumPizzas(int numPizzas) {
        if (numPizzas == 1 || numPizzas == 2 || numPizzas == 3) {
            pizzas = new Pizza[numPizzas];
        }
    }

    public void setPizza1(Pizza pizza1) {
        pizzas[0] = pizza1;
    }

    public void setPizza2(Pizza pizza2) {
        pizzas[1] = pizza2;
    }

    public void setPizza3(Pizza pizza3) {
        pizzas[2] = pizza3;
    }

    public double calcTotal() {
        double cost = 0;
        for (Pizza pizza : pizzas) {
            cost += pizza.calcCost();
        }
        return cost;
    }
}
