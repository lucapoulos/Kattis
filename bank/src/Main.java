import java.util.*;
/*
*  Problem:
* */
public class Main {
    // if i have two people with the same time, I want the one with more money
    // if there is not someone at the next time interval, find the next person and help them
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int t = scan.nextInt();
        PriorityQueue<Person> pq = new PriorityQueue<>(Person::compareTo);
        for (int i = 0; i < n; i++) {
            Person p = new Person(scan.nextInt(), scan.nextInt());
            pq.add(p);
        }
        int time = n;
        while(time >= 0) {
            Person p = pq.poll();

        }
        scan.close();
    }

    public static class Person implements Comparable<Person> {
        int cash;
        int time;
        public Person(int c, int t) {
            cash = c;
            time = t;
        }
        @Override
        public int compareTo(Person p) { // want to sort by least cash and most time (first person in queue has most cash and least time)
            int c = p.cash;
            int t = p.time;
            if (cash > c) return -1;
            if (cash < c) return 1;
            if (time < t) return -1;
            if (time > t) return 1;
            return 0; // people are equal
        }
    }
}
