import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/aboveaverage
* */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt(); // Test cases
        while(t != 0) {
            int n = scan.nextInt(); // Number of students
            double[] grades = new double[n];
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                grades[i] = scan.nextInt();
                sum += grades[i];
            }
            double average = sum / (double)n;
            double aboveAverage = 0.0;
            for (int i = 0; i < n; i++) {
                if (grades[i] > average) { // if student grade is above average grade
                    aboveAverage++;
                }
            }
            System.out.printf("%.3f%%\n" , 100.0 * aboveAverage / n); // Convert to percent and format
            t--;
        }
    }
}
