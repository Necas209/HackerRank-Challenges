package big_number;

import java.util.Scanner;
import java.math.BigInteger;

public class BigIntegerOps {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger a = scanner.nextBigInteger();
        BigInteger b = scanner.nextBigInteger();
        scanner.close();
        System.out.println(a.add(b));
        System.out.println(a.multiply(b));
    }
}
