package assignment7.c9p4;

/**
 * Created by Xavi on 4/29/2017.
 */
public class DenominatorIsZeroException extends Exception {
    @Override
    public String getMessage() {
        return "Denominator cannot be zero";
    }
}
