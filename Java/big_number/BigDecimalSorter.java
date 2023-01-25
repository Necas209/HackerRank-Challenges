package big_number;

import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class BigDecimalSorter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
        }
        sc.close();
        // Sort the string array in descending order
        // using the BigDecimal comparator
        Arrays.sort(s, 0, n, new Comparator<String>() {
            @Override
            public int compare(String a1, String a2) {
                return new BigDecimal(a2).compareTo(new BigDecimal(a1));
            }
        });
        // Print the sorted array
        for (int i = 0; i < n; i++) {
            System.out.println(s[i]);
        }
    }
}