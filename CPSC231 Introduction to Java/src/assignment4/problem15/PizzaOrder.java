package assignment4.problem15;

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
        pizzas = new Pizza[numPizzas];
    }

    public void setPizza(int index, Pizza newPizza) {
        pizzas[index] = newPizza;
    }

    public double calcTotal() {
        double cost = 0;
        for (Pizza pizza : pizzas) {
            cost += pizza.calcCost();
        }
        return cost;
    }
}
