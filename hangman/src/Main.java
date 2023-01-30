import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/hangman
* */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        HashSet<Character> occurrence = new HashSet<>(); // Contains remaining characters in the word at any round
        String word = scan.nextLine();
        String guess = scan.nextLine();

        for (int i = 0; i < word.length(); i++) { // Add characters to hashset
            char c = word.charAt(i);
            occurrence.add(c);
        }
        int j = 0; // Pointer to loop through chars in word
        int count = 0; // Number of guesses made by player 2
        while(occurrence.size() != 0) { // While there are no more chars in the hashset
            if (count == 10) {
                System.out.println("LOSE");
                break;
            }
            char g = guess.charAt(j);
            if (occurrence.contains(g)) {
                occurrence.remove(g);
            } else {
                count++;
            }
            j++;
        }
        if (occurrence.size() == 0) System.out.println("WIN");
        scan.close();
    }
}
