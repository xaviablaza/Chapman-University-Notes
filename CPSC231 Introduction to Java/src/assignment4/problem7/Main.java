package assignment4.problem7;

import java.util.Scanner;

public class Main {
	
	public static int NUM_DIGITS = 20;
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			System.out.println("Enter the first number: ");
			String num1 = "";
			while (true) {
				num1 = scanner.next();
				if (num1.length() > NUM_DIGITS) {
					System.out.println("Number should have " + NUM_DIGITS + " digits or fewer. Try again:");
				} else break;
			}
			System.out.println("Enter the second number: ");
			String num2 = "";
			while (true) {
				num2 = scanner.next();
				if (num1.length() > 20) {
					System.out.println("Number should have " + NUM_DIGITS + " digits or fewer. Try again:");
				} else break;
			}
			int[] arr1 = new int[NUM_DIGITS];
			int[] arr2 = new int[NUM_DIGITS];
			for (int i=0; i<NUM_DIGITS; ++i) {
				arr1[i] = 0;
				arr2[i] = 0;
			}
			int j = 0;
			for (int i=num1.length()-1; i>=0; --i) {
				arr1[j] = Character.getNumericValue(num1.charAt(i));
				j++;
			}
			j = 0;
			for (int i=num1.length()-1; i>=0; --i) {
				arr2[j] = Character.getNumericValue(num2.charAt(i));
				j++;
			}
			for (int i=0; i<NUM_DIGITS; ++i) {
				arr2[i] = arr1[i]+arr2[i];
				if (arr2[i] >= 10) {
					arr2[i]-=10;
					try {
						arr2[i+1]+=1;
					} catch (Exception e) {
						System.out.println("integer overflow");
					}
				}
			}
			String s = "";
			for (int i=0; i<NUM_DIGITS; ++i) {
				s = String.valueOf(arr2[i]) + s;
			}
			System.out.println("The sum of the two numbers is: " + s);
			System.out.println("Type 'exit' to exit, type any key to do more additions:");
			String input = scanner.next().toLowerCase();
			if (input.equalsIgnoreCase("exit")) break; 
		}
	}

}
