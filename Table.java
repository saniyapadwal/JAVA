import java.util.*;

public class Table {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number for table: ");
        int n = sc.nextInt();

        System.out.println("Multiplication Table of " + n + ":");
        for(int i=1; i<=10; i++){
            System.out.println(n+" x "+i+" = "+(n*i));
        }
    }
}
