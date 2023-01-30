import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/parking
* */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt(); // one truck
        int b = scan.nextInt(); // two trucks
        int c = scan.nextInt(); // three trucks
        int price = 0;
        int rates[] = {0, a, b, c};
        int time[] = new int[101];
        for (int i = 0; i < 3; i++) {
            int start = scan.nextInt();
            int end = scan.nextInt();
            for (int j = start; j < end; j++) { // Incrementing the times each truck spent during their interval
                time[j]++;
            }
        }
        for (int i = 0; i < time.length; i++) {
            price += rates[time[i]] * time[i];
        }
        System.out.println(price);
        scan.close();
    }
}
