package assignment1.chapter1;

public class Problem2 {

	public static void main(String[] args) {
		int numCoupons = 102;
		System.out.println("I have " + numCoupons + " coupons to spend.");
		int candyBars = numCoupons/10;
		numCoupons-=candyBars*10;
		int gumballs = numCoupons/3;
		numCoupons-=gumballs*3;
		System.out.println("I'll spend all my coupons on candy bars first and any remaining coupons on gumballs.");
		System.out.println("I bought " + candyBars + " candy bars and " + gumballs + " gumballs with " + numCoupons + " coupons left.");
	}

}
