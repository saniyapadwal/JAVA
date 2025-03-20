import java.util.Scanner;

public class Vote {
    public static void main(String[] args){
        System.out.print("Enter your age:");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();

        if (a >= 18){
            System.out.println("You are eligible to vote!");
        }
        else if (a < 18){
            System.out.println("Your are not eligible to vote!!");
        }
    }
}
