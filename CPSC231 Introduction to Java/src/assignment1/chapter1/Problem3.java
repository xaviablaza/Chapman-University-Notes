package assignment1.chapter1;

public class Problem3 {
	public static void main(String[] args) {
		String first = "xavi";
		String last = "ablaza";
		String pigLatin = first.substring(1, 2).toUpperCase() + first.substring(2) + first.substring(0, 1) + "ay" + " " + last.substring(1, 2).toUpperCase() + last.substring(2) + last.substring(0, 1) + "ay";
		System.out.println(pigLatin);
	}

}
