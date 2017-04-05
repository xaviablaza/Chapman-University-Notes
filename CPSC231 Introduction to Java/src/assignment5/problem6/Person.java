package assignment5.problem6;

/**
 * Created by Xavi on 4/5/2017.
 */
public class Person {
    private String name;

    public Person() {
        name = "No name";
    }

    public Person(String theName) {
        name = theName;
    }

    public Person(Person theObject) {
        name = theObject.getName();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String toString() {
        return name;
    }

    public boolean equals(Object other) {
        if (other instanceof Person) {
            Person p = (Person)other;
            return name.equals(p.getName());
        }
        return false;
    }
}
