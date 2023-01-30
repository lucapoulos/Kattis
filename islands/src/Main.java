import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/islands
* */
// go through array, if arr[i+1] > arr[i] start looking for end of island
// increment start
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        for (int i = 0; i < n; i++) {
            int count = 0;
            int t = scan.nextInt();
            int arr[] = new int[12];
            for (int j = 0; j < 12; j++) arr[j] = scan.nextInt();

            int start = 0;
            int left;
            for (int j = start; j < 11; j++) {
                if (arr[j + 1] > arr[j]) {
                    left = arr[j];
                    int index = j + 1;
                    while (arr[index + 1] > left) {
                        index++;
                    }
                    count++;
                    start++;
                }
            }
            System.out.print(t + " ");
            System.out.println(count);
        }
        scan.close();
    }
}
