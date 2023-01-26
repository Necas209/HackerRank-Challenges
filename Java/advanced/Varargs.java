package advanced;

import java.lang.reflect.Method;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Add {
    public void add(int... numbers) {
        int sum = 0;
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < numbers.length; i++) {
            sum += numbers[i];
            s.append(numbers[i]);
            if (i < numbers.length - 1) {
                s.append("+");
            }
        }
        System.out.println(s + "=" + sum);
    }
}

class Varargs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int n3 = sc.nextInt();
        int n4 = sc.nextInt();
        int n5 = sc.nextInt();
        int n6 = sc.nextInt();
        Add ob = new Add();
        ob.add(n1, n2);
        ob.add(n1, n2, n3);
        ob.add(n1, n2, n3, n4, n5);
        ob.add(n1, n2, n3, n4, n5, n6);
        Method[] methods = Add.class.getDeclaredMethods();
        Set<String> set = new HashSet<>();
        try {
            boolean overload = false;
            for (Method method : methods) {
                if (set.contains(method.getName())) {
                    overload = true;
                    break;
                }
                set.add(method.getName());
            }
            if (overload) {
                throw new Exception("Overloading not allowed");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}