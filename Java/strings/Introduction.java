import java.util.Scanner;

public class Introduction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        System.out.println(a.length() + b.length());
        System.out.println(a.compareTo(b) > 0 ? "Yes" : "No");
        String aCap = a.substring(0, 1).toUpperCase() + a.substring(1);
        String bCap = b.substring(0, 1).toUpperCase() + b.substring(1);
        System.out.println(aCap + " " + bCap);
        sc.close();
    }
}