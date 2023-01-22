import java.util.Scanner;

public class SubstringComparisons {
    public static String getSmallestAndLargest(String s, int k) {
        String[] substrings = new String[s.length() - k + 1];
        for (int i = 0; i < s.length() - k + 1; i++) {
            substrings[i] = s.substring(i, i + k);
        }
        String smallest = substrings[0];
        String largest = substrings[0];
        for (int i = 0; i < substrings.length; i++) {
            if (substrings[i].compareTo(smallest) < 0) {
                smallest = substrings[i];
            }
            if (substrings[i].compareTo(largest) > 0) {
                largest = substrings[i];
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
