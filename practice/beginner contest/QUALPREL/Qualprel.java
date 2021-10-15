// this is the first preliminary qualifier round
// problem code: QUALPREL

// Submission by Cole Fuerth, at University of Windsor

// PROBLEM:
/**\
 * two rounds, A and B
 * in each round, teams are sorted in descending order by their score
 * Each team with score >=K=1500 place advances to the pre-elimination round (meaning, if there are teams tied with k=1500th place, there are more than 1500 teams)
 * 
 * input:
 * first line contains T, the number of test cases
 * first line of each test case contains two integers, space-separated, N and K
 * second line of each test case contains N space separated characters, S1, S2, ..., Sn
 * 
 * output: for each test case, print a single line containing one integer: the number of qualified teams
 */

// ASSUME INPUT IS ON STDIN AND OUTPUT ON STDOUT

// picked C for speed

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Qualprel {
    public static void main(String args[]) {
        // input on stdin
        // need number of test cases
        int t, n, k; // number of test cases, number of entries in current case, pivot point

        // each value can be as big as 10^9, but integers can store up to 2.147*10^9, so
        // we are good
        int s[];

        // need number of test cases before starting
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt(); // get integer from first line

        int passing, pivot, j;
        // loop through each test case
        for (int c = 0; c < t; c++) {
            // two space-separated integers on next line
            n = sc.nextInt();
            k = sc.nextInt();
            // since n is number of entries, we need n spaces in s
            s = new int[n];
            // fill s with input
            for (int i = 0; i < n; i++)
                s[i] = sc.nextInt();
            // do quicksort on s
            Arrays.sort(s);
            j = n - k; // location of kth entry; k=1 will select final entry; k=n will select first
                       // (smallest) entry
            passing = k; // we know there are at least k passing teams
            pivot = s[j]; // faster to store pivot
            j--; // need to decrement j so it points to next spot to compare to
            // count number of additional passing grades
            for (; j >= 0 && s[j] == pivot; j--)
                passing++;
            // print number of passing grades to stdout
            System.out.println(passing);
        }
    }
}