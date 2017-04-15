package assignment6;

/**
 * Created by Xavi on 4/15/2017.
 */
public class Problem6 {
    public static void main(String[] args) {
        // 5 choose 3
        System.out.println(C(5, 3));
    }

    public static int C(int n, int r) {
        if (r == 0 || r == n) return 1;
        return C(n-1, r-1) + C(n-1, r);
    }
}
