import java.util.*;
/*
*  Problem:
* */
public class Main {
    public static void main(String[] args) {
        Stack<Character> stack = new Stack<>();
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        String lims = scan.nextLine();
        boolean failed = false;
        for (int i = 0; i < lims.length(); i++) {
            char c = lims.charAt(i);
            if (c == ' ') continue;
            if (c == '}' || c == ']' || c == ')') {
                if (stack.isEmpty()) {
                    System.out.println(c + " " + i);
                    failed = true;
                } else if (stack.peek() + 1 == c || stack.peek()+2 == c){
                    stack.pop();
                } else {
                    System.out.println(c + " " + i);
                    failed = true;
                }
            } else {
                stack.push(c);
            }
        }
        if (!failed) System.out.println("ok so far");

        scan.close();
    }
}
