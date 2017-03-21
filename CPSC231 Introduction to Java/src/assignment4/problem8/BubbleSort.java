package assignment4.problem8;

public class BubbleSort {

	public static void sort(double[] a) {
		for (int j=0; j<a.length-1; ++j) {
			for (int i=0; i<a.length-1; ++i) {
				if (a[i] > a[i+1]) {
					interchange(i, i+1, a);
				}
			}
		}
	}
	
	/**
	 * Precondition: i and j are legal indices for the array a.
	 * Postcondition: Values of a[i] and a[j] have been interchanged.
	 */
	private static void interchange(int i, int j, double[] a) {
		double temp;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp; // original value of a[i]
	}

}
