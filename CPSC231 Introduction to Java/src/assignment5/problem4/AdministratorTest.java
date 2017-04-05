package assignment5.problem4;

/**
 * Created by Xavi on 4/5/2017.
 */
public class AdministratorTest {
    public static void main(String[] args) {
        Administrator admin1 = new Administrator();
        admin1.setTitle("President");
        admin1.setResponsibility("Production");
        Administrator admin2 = new Administrator();
        admin2.setTitle("President");
        admin2.setResponsibility("Production");
        System.out.println(admin1.equals(admin2));
    }
}
