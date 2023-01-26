package oop;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class IteratorDemo {
    private static Iterator<Object> func(ArrayList<Object> mylist) {
        Iterator<Object> it = mylist.iterator();
        while (it.hasNext()) {
            Object element = it.next();
            if (element instanceof String)
                break;
        }
        return it;
    }

    public static void main(String[] args) {
        ArrayList<Object> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        list.add("###");
        for (int i = 0; i < m; i++) {
            list.add(sc.next());
        }
        Iterator<Object> it = func(list);
        while (it.hasNext()) {
            Object element = it.next();
            System.out.println((String) element);
        }
        sc.close();
    }
}
