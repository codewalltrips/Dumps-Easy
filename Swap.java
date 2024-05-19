import java.util.*;

class Swap {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2 numbers to be swapped");
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Before Swap=" + a + " " + b);
        a = a + b;
        b = a - b;
        a = a - b;
        System.out.println("After Swap=" + a + " " + b);

    }
}