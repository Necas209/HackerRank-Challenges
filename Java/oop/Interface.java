package oop;

import java.util.Scanner;
import java.util.stream.IntStream;

interface AdvancedArithmetic {
    int divisor_sum(int n);
}

class MyCalculator implements AdvancedArithmetic {
    @Override
    public int divisor_sum(int n) {
        return IntStream.rangeClosed(1, n).filter(i -> n % i == 0).sum();
    }
}

class Interface {
    public static void main(String[] args) {
        AdvancedArithmetic my_calculator = new MyCalculator();
        System.out.print("I implemented: ");
        ImplementedInterfaceNames(my_calculator);
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(my_calculator.divisor_sum(n) + "\n");
        sc.close();
    }

    static void ImplementedInterfaceNames(Object o) {
        Class<?>[] theInterfaces = o.getClass().getInterfaces();
        for (Class<?> theInterface : theInterfaces) {
            String interfaceName = theInterface.getName();
            System.out.println(interfaceName);
        }
    }
}