import java.util.*;
/*
* Problem: https://open.kattis.com/problems/guessinggame
*/
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        try {
            int min = 0, max = 11;

            while (true) {
                int guess = Integer.parseInt(scan.nextLine());
                if (guess == 0) break;
                String ans = scan.nextLine();

                if (ans.equals("too low") && guess > min) {
                    min = guess;
                } else if (ans.equals("too high") && guess < max) {
                    max = guess;
                } else if (ans.equals("right on")) {
                    if (guess > min && guess < max) System.out.println("Stan may be honest");
                    else System.out.println("Stan is dishonest");
                    min = 0;
                    max = 11;
                }
            }

        } catch (Exception e) {

        }
    }

}
