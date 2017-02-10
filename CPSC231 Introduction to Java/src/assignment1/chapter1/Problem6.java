package assignment1.chapter1;

public class Problem6 {

	public static void main(String[] args) {
        double PI = 3.14;
        int GEAR_SIZE = 100;
        int CADENCE = 90;
        double speed = GEAR_SIZE * PI / 12 / 5280 * CADENCE * 60;
        System.out.println(speed);
  }
}
