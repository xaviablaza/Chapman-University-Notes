package assignment3.chapter4.problem11;

/**
 * Created by Xavi on 3/6/2017.
 */
public class Pizza {
    private String pizzaSize;
    private int numCheeseToppings;
    private int numPepperoniToppings;
    private int numHamToppings;

    public Pizza(String pizzaSize, int numCheeseToppings, int numPepperoniToppings, int numHamToppings) {
        this.pizzaSize = pizzaSize;
        this.numCheeseToppings = numCheeseToppings;
        this.numPepperoniToppings = numPepperoniToppings;
        this.numHamToppings = numHamToppings;
    }

    public String getPizzaSize() {
        return pizzaSize;
    }

    public void setPizzaSize(String pizzaSize) {
        this.pizzaSize = pizzaSize;
    }

    public int getNumCheeseToppings() {
        return numCheeseToppings;
    }

    public void setNumCheeseToppings(int numCheeseToppings) {
        this.numCheeseToppings = numCheeseToppings;
    }

    public int getNumPepperoniToppings() {
        return numPepperoniToppings;
    }

    public void setNumPepperoniToppings(int numPepperoniToppings) {
        this.numPepperoniToppings = numPepperoniToppings;
    }

    public int getNumHamToppings() {
        return numHamToppings;
    }

    public void setNumHamToppings(int numHamToppings) {
        this.numHamToppings = numHamToppings;
    }

    public double calcCost() {
        double cost = 0;
        if (pizzaSize.equalsIgnoreCase("small")) {
            cost = 10 + 2*(numCheeseToppings+numHamToppings+numPepperoniToppings);
        } else if (pizzaSize.equalsIgnoreCase("medium")) {
            cost = 12 + 2*(numCheeseToppings+numHamToppings+numPepperoniToppings);
        } else if (pizzaSize.equalsIgnoreCase("large")) {
            cost = 14 + 2*(numCheeseToppings+numHamToppings+numPepperoniToppings);
        }
        return cost;
    }

    public String getDescription() {
        return pizzaSize + " pizza, " + numCheeseToppings + " cheese toppings, " +  numPepperoniToppings + " pepperoni toppings, " + numHamToppings + " ham toppings, cost: " + calcCost();
    }
}
