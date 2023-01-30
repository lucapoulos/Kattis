import java.util.*;
/*
*  Problem:
* */
// aaaaaaaaaardvarkk -> ardvrk
// aaaaaaaaaaaaaaa -> aa, same for consonants
// First and last vowels should not be removed
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        HashSet<Character> vowels = new HashSet<>();
        StringBuilder strF = new StringBuilder();
        vowels.add('a'); vowels.add('e'); vowels.add('i'); vowels.add('o'); vowels.add('u');

        int n = Integer.parseInt(scan.nextLine());
        while (n > 0) {
            StringBuilder str = new StringBuilder();
            String word = scan.next();
            char lastC = word.charAt(0);
            str.append(lastC);
            strF.append(lastC);
            for (int i = 1; i < word.length(); i++) {
                char c = word.charAt(i);
                if (c!= lastC) str.append(c);
                lastC = c;
            }

            for (int i = 1; i < str.length(); i++) {
                char c = str.charAt(i);
                if (!vowels.contains(c) || i == str.length() - 1) strF.append(c);
            }
            if (scan.hasNext()) strF.append(" "); //Adding spaces unless last word
            n--;
        }
        System.out.println(strF);
        scan.close();
    }
}
