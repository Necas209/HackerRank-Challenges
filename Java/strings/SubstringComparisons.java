package strings;

import java.util.Scanner;

public class SubstringComparisons {
    public static String getSmallestAndLargest(String s, int k) {
        String[] substrings = new String[s.length() - k + 1];
        for (int i = 0; i < s.length() - k + 1; i++) {
            substrings[i] = s.substring(i, i + k);
        }
        String smallest = substrings[0];
        String largest = substrings[0];
        for (String substring : substrings) {
            if (substring.compareTo(smallest) < 0) {
                smallest = substring;
            }
            if (substring.compareTo(largest) > 0) {
                largest = substring;
            }
        }
        return smallest + "\n" + largest;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
        System.out.println(getSmallestAndLargest(s, k));
    }
}
