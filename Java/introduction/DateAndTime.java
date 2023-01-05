package introduction;

import java.time.LocalDate;
import java.util.Scanner;

public class DateAndTime {
    private static String getDay(int month, int day, int year) {
        LocalDate date = LocalDate.of(year, month, day);
        return date.getDayOfWeek().toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int month = sc.nextInt();
        int day = sc.nextInt();
        int year = sc.nextInt();
        sc.close();
        System.out.println(getDay(month, day, year));
    }
}
