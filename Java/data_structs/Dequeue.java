package data_structs;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Scanner;

public class Dequeue {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        HashSet<Integer> set = new HashSet<>();
        int n = in.nextInt();
        int m = in.nextInt();
        int max = 0;
        for (int i = 0; i < n; i++) {
            int num = in.nextInt();
            deque.add(num);
            set.add(num);
            if (deque.size() == m) {
                max = Math.max(max, set.size());
                int first = deque.remove();
                if (!deque.contains(first)) {
                    set.remove(first);
                }
            }
        }
        in.close();
        System.out.println(max);
    }
}