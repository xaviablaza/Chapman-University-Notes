package assignment5.problem6;

/**
 * Created by Xavi on 4/5/2017.
 */
public class Test {
    public static void main(String[] args) {
        Person p1 = new Person("Xavi");
        Person p2 = new Person("John");
        Vehicle v1 = new Vehicle("Benz", 5, p1);
        Truck v2 = new Truck("Benz", 5, p1);
        v2.setLoadCapacity(5.5);
        v2.setTowingCapacity(4);
        System.out.println(p1.equals(p2));
        System.out.println(v1.equals(v2));
    }
}
