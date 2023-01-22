package oop;

import java.util.ArrayList;
import java.util.Scanner;

class Student {
}

class Rockstar {
}

class Hacker {
}

public class Instanceof {
    private static String count(ArrayList<Object> mylist) {
        int a = 0, b = 0, c = 0;
        for (Object element : mylist) {
            if (element instanceof Student)
                a++;
            if (element instanceof Rockstar)
                b++;
            if (element instanceof Hacker)
                c++;
        }
        return String.format("%d %d %d", a, b, c);
    }

    public static void main(String[] args) {
        ArrayList<Object> mylist = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String s = sc.next();
            if (s.equals("Student"))
                mylist.add(new Student());
            if (s.equals("Rockstar"))
                mylist.add(new Rockstar());
            if (s.equals("Hacker"))
                mylist.add(new Hacker());
        }
        sc.close();
        System.out.println(count(mylist));
    }
}