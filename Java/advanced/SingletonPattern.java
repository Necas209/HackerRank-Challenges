package advanced;

import java.util.Scanner;

class Singleton {
    private static final Singleton instance = new Singleton();
    public String str;

    private Singleton() {
    }

    public static Singleton getSingleInstance() {
        return instance;
    }
}

public class SingletonPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Singleton x = Singleton.getSingleInstance();
        x.str = sc.nextLine();
        sc.close();
        System.out.printf("Hello I am a singleton! Let me say %s to you", x.str);
    }
}
