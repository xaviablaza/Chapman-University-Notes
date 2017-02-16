package assignment1.chapter3;

/**
 * Created by Xavi on 2/15/2017.
 */
public class Problem8 {
    public static void main(String[] args) {
        for (int t=0; t<9; ++t) {
            for (int o=0; o<9; ++o) {
                for (int g=0; g<9; ++g) {
                    for (int d=0; d<9; ++d) {
                        // Test each variable is unique
                        if (t != o && t != g && t != d && o != g && o != d && g != d) {
                            // Test that the equation is satisfied
                            String tooStr = String.valueOf(t)+String.valueOf(o)+String.valueOf(o);
                            int too4 = 4*Integer.valueOf(tooStr);
                            String goodStr = String.valueOf(g)+String.valueOf(o)+String.valueOf(o)+String.valueOf(d);
                            int good = Integer.valueOf(goodStr);
                            if (too4 == good) {
                                System.out.println("TOO + TOO + TOO + TOO = GOOD");
                                System.out.println(tooStr + " + " + tooStr + " + " + tooStr + " + " + tooStr + " = " + goodStr);
                                System.out.println("T = " + t);
                                System.out.println("O = " + o);
                                System.out.println("G = " + g);
                                System.out.println("D = " + d);
                                return;
                            }
                        }
                    }
                }
            }
        }

    }
}
