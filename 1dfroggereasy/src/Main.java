import java.util.*;
/*
*  Problem:
* */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int s = scan.nextInt() - 1; // start and cur position
        int m = scan.nextInt();
        int hops = 0; // hops
        HashSet<Integer> indicies = new HashSet<>();
        List<Integer> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            board.add(scan.nextInt());
        }
        while (true) {
            if (indicies.contains(s)) {
                System.out.println("cycle\n" + hops);
                break;
            } else if (board.get(s) == m) {
                System.out.println("magic\n" + hops);
                break;
            } else if (s < 0) {
                System.out.println("left\n" + hops);
                break;
            }else if (s > n - 1) {
                System.out.println("right\n" + hops);
                break;
            }
            indicies.add(s);
            s += board.get(s);
            hops++;
        }
        scan.close();
    }
}
