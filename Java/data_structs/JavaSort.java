package data_structs;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

record Student(int id, String firstName, double cGPA) {
}

public class JavaSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());
        List<Student> studentList = new ArrayList<>();
        while (testCases > 0) {
            int id = in.nextInt();
            String firstName = in.next();
            double cgpa = in.nextDouble();
            Student st = new Student(id, firstName, cgpa);
            studentList.add(st);
            testCases--;
        }
        in.close();
        studentList.sort((o1, o2) -> {
            if (o1.cGPA() != o2.cGPA())
                return o1.cGPA() < o2.cGPA() ? 1 : -1;
            if (o1.firstName().equals(o2.firstName()))
                return o1.id() - o2.id();
            return o1.firstName().compareTo(o2.firstName());
        });
        for (Student st : studentList) {
            System.out.println(st.firstName());
        }
    }
}
