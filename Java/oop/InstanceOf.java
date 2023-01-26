package oop;

import java.util.ArrayList;
import java.util.Scanner;

class Student {
}

class Rockstar {
}

class Hacker {
}

public class InstanceOf {
    private static String count(ArrayList<Object> list) {
        int a = 0, b = 0, c = 0;
        for (Object element : list) {
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
        ArrayList<Object> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String s = sc.next();
            if (s.equals("Student"))
                list.add(new Student());
            if (s.equals("Rockstar"))
                list.add(new Rockstar());
            if (s.equals("Hacker"))
                list.add(new Hacker());
        }
        sc.close();
        System.out.println(count(list));
    }
}