package strings;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TagContentExtractor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());
        Pattern pattern = Pattern.compile("<(.+)>([^<>]+)</\\1>");
        while (testCases > 0) {
            boolean matched = false;
            String string = in.nextLine();
            Matcher matcher = pattern.matcher(string);
            while (matcher.find()) {
                System.out.println(matcher.group(2));
                matched = true;
            }
            if (!matched) {
                System.out.println("None");
            }
            testCases--;
        }
        in.close();
    }
}
