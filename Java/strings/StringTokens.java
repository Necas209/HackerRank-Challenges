package strings;

import java.util.Scanner;

public class StringTokens {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        scan.close();
        String delimiters = "[ !,?._'@]+";
        String[] tokens = s.trim().split(delimiters);
        if (tokens.length == 0 || tokens[0].equals(""))
            System.out.println(0);
        else
            System.out.println(tokens.length);
        for (String token : tokens) {
            System.out.println(token);
        }
    }
}
