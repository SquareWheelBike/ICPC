import java.util.*;

public class Maxdist {

    /**
     * Each case has two lines:
     * <p>
     * First line is N, the number of integers; second is the array A of N integers.
     * 
     * @param sc scanner from which to read input
     * @return array A
     */
    public static int[] getCaseArray(Scanner sc) {
        int n = Integer.parseInt(sc.nextLine());
        int B[] = new int[n];
        String[] input = sc.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            B[i] = Integer.parseInt(input[i]);
        }
        return B;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        // first line of input is number of test cases, t
        int t = Integer.parseInt(sc.nextLine());

        // loop through c test cases
        for (int c = 0; c < t; ++c) {
            int[] B = getCaseArray(sc);
            // now that input has been injested, work with it
        }

        sc.close();
    }
}