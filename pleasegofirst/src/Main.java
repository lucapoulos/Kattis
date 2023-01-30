import java.util.*;
import java.util.concurrent.TimeUnit;
/*
 *  Problem: https://open.kattis.com/problems/pleasegofirst
 * */

public class Main {
    public static HashMap<Character, Integer> lCI = new HashMap<>();
    public static int waitTime(char[] c) {

        for (int i = 0; i < c.length; i++) {
            lCI.put(c[i], i);
        }
        int waitTime = 0;
        for (Character i: c) {
            waitTime += lCI.get(i) * 5; //Every char must wait until their last friend
        }
        return waitTime;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long start = System.nanoTime();

        int t = Integer.parseInt(scan.nextLine());
        while (t!= 0) {
            lCI = new HashMap<>();
            int n = Integer.parseInt(scan.nextLine()); // length of line
            String line = scan.nextLine();
            char[] c = line.toCharArray();
            for (int i = 0; i < c.length; i++) {
                lCI.put(c[i], i); // Recording last index of each char in string
            }
            int originalTime = waitTime(c); // Original total time waited

            for (int i = 0; i < n ; i++) { //Loop through char in array and swap if last index of friend is higher
                for (int j = 0; j < n - 1; j++) {
                    int index = lCI.get(c[j]);
                    int nextIndex = lCI.get(c[j+1]);

                    if (index > nextIndex) {
                        if (j+1 == nextIndex) lCI.put(c[j+1], j); // Updating hash
                        if (j == index) lCI.put(c[j], j+1);
                        char temp = c[j];
                        c[j] = c[j+1];
                        c[j+1] = temp;
                    }
                }
            }
            System.out.println(originalTime - waitTime(c));
            t--;
        }
        long end = System.nanoTime();
        // System.out.printf("Time was %d milliseconds\n", TimeUnit.MILLISECONDS.convert(end - start, TimeUnit.NANOSECONDS));
    }
}