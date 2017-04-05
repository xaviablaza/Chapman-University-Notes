package assignment5.problem6;

/**
 * Created by Xavi on 4/5/2017.
 */
public class Truck extends Vehicle {
    private double loadCapacity;
    private int towingCapacity;

    public Truck(String manufacturer, int numCylinders, Person owner) {
        super(manufacturer, numCylinders, owner);
    }

    public double getLoadCapacity() {
        return loadCapacity;
    }

    public void setLoadCapacity(double loadCapacity) {
        this.loadCapacity = loadCapacity;
    }

    public int getTowingCapacity() {
        return towingCapacity;
    }

    public void setTowingCapacity(int towingCapacity) {
        this.towingCapacity = towingCapacity;
    }

    @Override
    public String toString() {
        return super.toString() + " with " + loadCapacity + "T load capacity and " + towingCapacity + "T towing capacity";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Truck) {
            Truck t = (Truck)obj;
            return (getLoadCapacity() == t.getLoadCapacity()
                    && getTowingCapacity() == t.getTowingCapacity()
                    && getManufacturer().equals(t.getManufacturer())
                    && getNumCylinders() == t.getNumCylinders()
                    && getOwner().equals(t.getOwner()));
        }
        return false;
    }
}
