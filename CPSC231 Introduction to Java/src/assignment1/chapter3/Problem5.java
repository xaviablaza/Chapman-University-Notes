package assignment1.chapter3;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem5 {
    public static void main(String[] args) {
        double debt = 1000;
        double monthlyInterest = 0.015;
        int monthlyPayment = 50;
        int numMonths = 0;
        double totalInterestPaid = 0;
        while (debt > 0) {
            // monthly payment used to pay the interest
            double interestPaid = monthlyInterest*debt;
            totalInterestPaid += interestPaid;

            // whatever is left is used to pay the debt
            debt = debt - (monthlyPayment - interestPaid);
            numMonths++;
        }
        System.out.println("It will take " + numMonths + " months to pay off the loan.");
        System.out.println("The total amount of interest paid over the life of the loan is: $" + totalInterestPaid);
    }
}
