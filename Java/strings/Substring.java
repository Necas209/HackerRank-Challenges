import java.util.Scanner;

public class Substring {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        int start = in.nextInt();
        int end = in.nextInt();
        in.close();
        System.out.println(s.substring(start, end));
    }
}
