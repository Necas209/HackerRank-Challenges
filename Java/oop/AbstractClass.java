package oop;

import java.util.Scanner;

abstract class Book {
    String title;

    String getTitle() {
        return title;
    }

    abstract void setTitle(String s);
}

class MyBook extends Book {
    @Override
    void setTitle(String s) {
        title = s;
    }
}

public class AbstractClass {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        scanner.close();
        Book book = new MyBook();
        book.setTitle(title);
        System.out.println("The title is: " + book.getTitle());
    }
}
