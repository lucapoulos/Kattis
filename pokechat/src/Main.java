import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/pokechat
* */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String S= scan.nextLine();
        String id = scan.nextLine();
        int left = 0;
        int right = 3;
        while (right <= id.length()) {
            String str = id.substring(left, right); // Looking at the string in substrings of length 3
            int i = 0;
            for (int j = 0; j < 3; j++) { // Ignoring zeroes if they exist
                char c = str.charAt(j);
                if(c == '0')  {
                    continue;
                }
                i = Integer.parseInt(str.substring(j, 3)); //
                System.out.print(S.charAt(i - 1)); // Index is 1 based for id numbers => 1 equals 0 index
                break; // Escape once we print a char
            }
            right += 3;
            left += 3;
        }
        scan.close();
    }
}
