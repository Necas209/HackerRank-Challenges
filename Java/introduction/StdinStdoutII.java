package introduction;

import java.util.Scanner;

public class StdinStdoutII {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int no = scanner.nextInt();
        double db = scanner.nextDouble();
        scanner.nextLine();
        String str = scanner.nextLine();
        System.out.println("String: " + str);
        System.out.println("Double: " + db);
        System.out.println("Int: " + no);
        scanner.close();
    }
}
