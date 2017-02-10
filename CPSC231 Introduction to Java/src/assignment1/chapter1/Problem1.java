package assignment1.chapter1;

public class Problem1 {

	public static void main(String[] args) {
		final int RUNNING_METS = 10;
		final int BASKETBALL_METS = 8;
		final int SLEEPING_METS = 1;
		final double WEIGHT_KILOS = 150 * 2.2;
		final int RUNNING_MINS = 30;
		final int BASKETBALL_MINS = 30;
		final int SLEEPING_MINS = 360;
		double caloriesBurnt = 0.0175 * RUNNING_METS * WEIGHT_KILOS * RUNNING_MINS;
		caloriesBurnt += 0.0175 * BASKETBALL_METS * WEIGHT_KILOS * BASKETBALL_MINS;
		caloriesBurnt += 0.0175 * SLEEPING_METS * WEIGHT_KILOS * SLEEPING_MINS;
		System.out.println(caloriesBurnt);
	}

}
