package data_structs;

import java.util.BitSet;
import java.util.Scanner;

public class Bitset {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        BitSet b1 = new BitSet(n);
        BitSet b2 = new BitSet(n);
        for (int i = 0; i < m; i++) {
            String op = in.next();
            int x = in.nextInt();
            int y = in.nextInt();
            BitSet left = x == 1 ? b1 : b2;
            BitSet right = y == 1 ? b1 : b2;
            switch (op) {
                case "AND" -> left.and(right);
                case "OR" -> left.or(right);
                case "XOR" -> left.xor(right);
                case "FLIP" -> left.flip(y);
                case "SET" -> left.set(y);
            }
            System.out.println(b1.cardinality() + " " + b2.cardinality());
        }
    }
}
