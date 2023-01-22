import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String A = scan.next();
        scan.close();
        String B = new StringBuilder(A).reverse().toString();
        System.out.println(A.equals(B) ? "Yes" : "No");
    }
}
