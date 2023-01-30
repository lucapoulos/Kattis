import java.util.*;
/*
 *  Problem:
 * */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); // num mins

        int ranges[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            ranges[i][0] = x;
            ranges[i][1] = y;
        }
        Arrays.sort(ranges, (o1, o2) -> { // Sort 2D array by first column
            Integer a = o1[0];
            Integer b = o2[0];
            return a.compareTo(b);
        });
        int min = ranges[0][1];
        int numRooms = 1;
        for (int i = 1; i < n; i++) {
            if (ranges[i][0] > min) { // if start is greater than current min
                numRooms++;
                min = ranges[i][1];
            } else if (ranges[i][1] < min) { // if end index is less than current min
                min = ranges[i][1];
            }
        }
        System.out.println(numRooms);
        scan.close();
    }
}

