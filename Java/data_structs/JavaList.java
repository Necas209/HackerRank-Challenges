package data_structs;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JavaList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            String query = sc.next();
            if (query.equals("Insert")) {
                int index = sc.nextInt();
                int value = sc.nextInt();
                list.add(index, value);
            } else if (query.equals("Delete")) {
                int index = sc.nextInt();
                list.remove(index);
            }
        }
        sc.close();
        for (Integer integer : list) {
            System.out.print(integer + " ");
        }
    }
}
