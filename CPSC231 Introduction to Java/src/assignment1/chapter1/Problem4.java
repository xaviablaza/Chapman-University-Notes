package assignment1.chapter1;

public class Problem4 {

	public static void main(String[] args) {
		// All values below are in grams
		final double SWEETENER_DEATH_THRESHOLD = 5;
		final double MOUSE_WEIGHT = 20;
		final double DIETER_WEIGHT_CURR = 80000;
		final double DIETER_WEIGHT_DESIRED = 63500;

		final double DIET_SODA = 0.001;

		double ratio = SWEETENER_DEATH_THRESHOLD / MOUSE_WEIGHT;

		// How much soda pop the dieter can drink before dying
		double sodaPopGrams = ratio * DIETER_WEIGHT_DESIRED;

		double maxSodaPopServings = sodaPopGrams / DIET_SODA;

		System.out.println("My friend can drink " + maxSodaPopServings + " soda pop servings before dying.");
	}

}
