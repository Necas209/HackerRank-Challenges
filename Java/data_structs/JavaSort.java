package data_structs;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

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
        studentList.sort(Comparator.comparing(Student::getCGPA, Comparator.reverseOrder())
                .thenComparing(Student::getName)
                .thenComparing(Student::getID));
        for (Student st : studentList) {
            System.out.println(st.getName());
        }
    }
}
