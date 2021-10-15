import java.util.*;
import java.lang.*;

public class Avgmat{
    private static int manhattanDistance(int[] a, int[] b){
        // distance is just the sum of differences of axes
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
    private static void runTestCase(Scanner sc){
        List<int[]> cellsList = new LinkedList<>(); // need a set of integer pairs for coordinates
        // each 'first line' in test case is two space separated integers, n and m
        String[] nm = sc.nextLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);
        for (int i = 0; i<n; i++){
            char[] line = sc.nextLine().toCharArray();
            for (int j = 0; j < line.length; j++){
                // each character is either a 0 or 1; if 1, then it is a house
                if (line[j] == '1'){
                    int[] cell = {i, j};
                    cellsList.add(cell);
                }
            }
        }

        // at this point, we have the set of all List in this test case
        // get the distance of all cells; add them to a map from distance -> cell
        int[] distanceCount = new int[n+m-2];
        int[][] cells = new int[cellsList.size()][2];
        cellsList.toArray(cells);
        for (int i=0; i<cells.length; i++){
            for (int j=i+1; j<cells.length; j++){
                distanceCount[manhattanDistance(cells[i], cells[j]) - 1]++;
            }
        }
        for (int i=0; i<distanceCount.length; i++){
            System.out.print(distanceCount[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) throws java.lang.Exception{
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());    // first line is always number of test cases
        for (int i=0; i<t; i++)
            runTestCase(sc);
    }
}