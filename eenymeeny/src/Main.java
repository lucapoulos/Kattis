import java.util.*;
/*
*  Problem: https://open.kattis.com/problems/eenymeeny
* */
public class Main {
    public static void main(String[] args) {
        LinkedList<String> names = new LinkedList<>();
        LinkedList<String> team1 = new LinkedList<>();
        LinkedList<String> team2 = new LinkedList<>();
        Scanner scan = new Scanner(System.in);
        String[] rhymes = scan.nextLine().split(" ");
        int count = rhymes.length - 1; // Number of spaces in rhyme
        int size = scan.nextInt();
        scan.nextLine(); // clear scanner

        while (scan.hasNext()) { // Add names to names list
            names.add(scan.next());
        }
        int currI = 0; // Current index
        boolean team = true; // Switch to alternate between teams
        while (!names.isEmpty()) {
            currI = ((currI + count) % names.size()); // <--- Varies index to remove based on rhyme
            if (team) { // adding to team one
                team = !team;
                team1.add(names.get(currI));
            } else { // adding to team two
                team2.add(names.get(currI));
                team = !team;
            }
            names.remove(currI);
        }
        System.out.println(team1.size());
        while (!team1.isEmpty()) {
            System.out.println(team1.poll());
        }
        System.out.println(team2.size());
        while (!team2.isEmpty()) {
            System.out.println(team2.poll());
        }
        scan.close();
    }
}
