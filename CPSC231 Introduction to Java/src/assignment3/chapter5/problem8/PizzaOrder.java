package assignment3.chapter5.problem8;

import assignment3.chapter4.problem11.Pizza;

/**
 * Created by Xavi on 3/6/2017.
 */
public class PizzaOrder {
    private Pizza pizza1 = null;
    private Pizza pizza2 = null;
    private Pizza pizza3 = null;
    private int numPizzas = 0;

    public PizzaOrder() {

    }

    public PizzaOrder(PizzaOrder pizzaOrder) {
        if (pizzaOrder.getPizza1() != null) {
            Pizza pizza = pizzaOrder.getPizza1();
            pizza1 = new Pizza(pizza.getPizzaSize(), pizza.getNumCheeseToppings(), pizza.getNumPepperoniToppings(), pizza.getNumHamToppings());
        }
        if (pizzaOrder.getPizza2() != null) {
            Pizza pizza = pizzaOrder.getPizza2();
            pizza2 = new Pizza(pizza.getPizzaSize(), pizza.getNumCheeseToppings(), pizza.getNumPepperoniToppings(), pizza.getNumHamToppings());
        }
        if (pizzaOrder.getPizza3() != null) {
            Pizza pizza = pizzaOrder.getPizza3();
            pizza3 = new Pizza(pizza.getPizzaSize(), pizza.getNumCheeseToppings(), pizza.getNumPepperoniToppings(), pizza.getNumHamToppings());
        }
        numPizzas = pizzaOrder.getNumPizzas();
    }

    public int getNumPizzas() {
        return numPizzas;
    }

    public void setNumPizzas(int numPizzas) {
        if (numPizzas == 1 || numPizzas == 2 || numPizzas == 3) {
            this.numPizzas = numPizzas;
        }
    }

    public Pizza getPizza1() {
        return pizza1;
    }

    public void setPizza1(Pizza pizza1) {
        this.pizza1 = pizza1;
    }

    public Pizza getPizza2() {
        return pizza2;
    }

    public void setPizza2(Pizza pizza2) {
        this.pizza2 = pizza2;
    }

    public Pizza getPizza3() {
        return pizza3;
    }

    public void setPizza3(Pizza pizza3) {
        this.pizza3 = pizza3;
    }

    public double calcTotal() {
        double cost = 0;
        if (pizza1 != null) cost+=pizza1.calcCost();
        if (pizza2 != null) cost+= pizza2.calcCost();
        if (pizza3 != null) cost+= pizza3.calcCost();
        return cost;
    }
}
