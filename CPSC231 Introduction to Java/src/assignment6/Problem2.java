package assignment6;

/**
 * Created by Xavi on 4/15/2017.
 */
public class Problem2 {
    public static void main(String[] args) {
        // Handshake with 5 people in the room
        System.out.println(handshake(5));
    }

    public static int handshake(int numPeople) {
        if (numPeople == 0) return 0;
        if (numPeople >= 1) return numPeople + handshake(numPeople-1);
        return -1;
    }
}
