package introduction;

import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

public class CurrencyFormatter {
   public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    BigDecimal payment = scanner.nextBigDecimal();
    scanner.close();
    NumberFormat us = NumberFormat.getCurrencyInstance(Locale.US);
    //noinspection deprecation
    NumberFormat india = NumberFormat.getCurrencyInstance(new Locale("en", "IN"));
    NumberFormat china = NumberFormat.getCurrencyInstance(Locale.CHINA);
    NumberFormat france = NumberFormat.getCurrencyInstance(Locale.FRANCE);
    System.out.println("US: " + us.format(payment));
    System.out.println("India: " + india.format(payment));
    System.out.println("China: " + china.format(payment));
    System.out.println("France: " + france.format(payment));
   }
}