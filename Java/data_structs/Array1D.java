package data_structs;

import java.util.Scanner;

class Part1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();
        for (int j : a) {
            System.out.println(j);
        }
    }
}

class Part2 {
    public static boolean isSolvable(int leap, int[] game, int i) {
        if (i >= game.length) {
            return true;
        } else if (i < 0 || game[i] == 1) {
            return false;
        }
        game[i] = 1; // marks as visited
        return isSolvable(leap, game, i + leap)
                || isSolvable(leap, game, i + 1)
                || isSolvable(leap, game, i - 1);
    }

    public static boolean canWin(int leap, int[] game) {
        return isSolvable(leap, game, 0);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }
            System.out.println(canWin(leap, game) ? "YES" : "NO");
        }
        scan.close();
    }
}