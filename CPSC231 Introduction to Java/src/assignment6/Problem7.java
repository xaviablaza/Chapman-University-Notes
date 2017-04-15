package assignment6;

/**
 * Created by Xavi on 4/15/2017.
 */
public class Problem7 {
    public static void main(String[] args) {
        // Three disks, with towers A, B, and C
        hanoi(3, 'A', 'B', 'C');
    }

    public static void hanoi(int n, char src, char dest, char aux) {
        if (n == 1) {
            System.out.println("Move from " + src + " to " + dest);
        } else {
            hanoi(n - 1, src, aux, dest);
            System.out.println("Move from " + src + " to " + dest);
            hanoi(n - 1, aux, dest, src);
        }
    }
}
