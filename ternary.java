import java.util.*;
class ternary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 3 numbers to be compared");
        int a=0, b=0, c=0, x=0;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        x = a;
        x = (a > b && a > c) ? a : b > c ? b : c;
        System.out.println("Greatest=" + x);

    }
}