import java.util.*;

class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = 0, y = 1, s = 0, a = 0;
        a = sc.nextInt();
        if (a == 1) {
            System.out.println("0");
        } else if (a == 2) {
            System.out.println("0 1");
        } else if (a > 2) {
            System.out.println("0  1");
            for (int i = 1; i < a - 2; i++) {
                s = x + y;
                System.out.println("" + s);
                x = y;
                y = s;
            }
        }
    }
}