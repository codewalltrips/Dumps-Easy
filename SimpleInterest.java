import java.util.*;

class SimpleInterest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double p = 0, r = 0, t = 0;
        System.out.println("Enter the Principal, rate of interest and time values respectively");
        p = sc.nextDouble();
        r = sc.nextDouble();
        t = sc.nextDouble();
        System.out.println("The Simple Interest is:" + (p * r * t) / 100);
    }
}