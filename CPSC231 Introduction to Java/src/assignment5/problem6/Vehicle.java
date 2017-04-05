package assignment5.problem6;

/**
 * Created by Xavi on 4/5/2017.
 */
public class Vehicle {
    private String manufacturer;
    private int numCylinders;
    private Person owner;

    public Vehicle(String manufacturer, int numCylinders, Person owner) {
        this.manufacturer = manufacturer;
        this.numCylinders = numCylinders;
        this.owner = owner;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public int getNumCylinders() {
        return numCylinders;
    }

    public void setNumCylinders(int numCylinders) {
        this.numCylinders = numCylinders;
    }

    public Person getOwner() {
        return owner;
    }

    public void setOwner(Person owner) {
        this.owner = owner;
    }

    @Override
    public String toString() {
        return (manufacturer + " Car with " + numCylinders + " cylinders owned by " + owner);
    }

}
