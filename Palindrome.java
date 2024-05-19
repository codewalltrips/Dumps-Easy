import java.util.*;

class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 0, b = 0, s = 0;
        System.out.println("Enter number to check");
        a = sc.nextInt();
        b = a;
        while (a > 0) {
            s = (s * 10) + (a % 10);
            a = a / 10;
        }
        if (s == b) {

         

            
        
            System.out.println("Not a Palindrome");}
    }
}