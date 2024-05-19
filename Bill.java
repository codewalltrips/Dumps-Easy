import java.util.*;
class Bill{
    public static void main(String []args){
        Scanner sc= new Scanner(System.in);
        int a=0;
        System.out.println("Enter the unit");
        a=sc.nextInt();
        double amt;
        if (a>=0&&a<=99)
            amt=a*.30;
        else if (a<=100&&a>=499)
            amt=a*.28;
        else 
            amt=a*.25;
        System.out.println("Cost is Rs"+amt);
    }
}