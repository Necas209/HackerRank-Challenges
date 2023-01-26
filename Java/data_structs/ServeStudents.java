package data_structs;

import java.util.*;

class Student implements Comparable<Student> {
    private final int id;
    private final String firstName;
    private final double cGPA;

    public Student(int id, String firstName, double cGPA) {
        this.id = id;
        this.firstName = firstName;
        this.cGPA = cGPA;
    }

    public String getName() {
        return firstName;
    }

    public int getID() {
        return id;
    }

    public double getCGPA() {
        return cGPA;
    }

    @Override
    public int compareTo(Student o) {
        return Comparator.comparing(Student::getCGPA, Comparator.reverseOrder())
                .thenComparing(Student::getName)
                .thenComparing(Student::getID)
                .compare(this, o);
    }
}

class Priorities {
    public List<Student> getStudents(List<String> events) {
        PriorityQueue<Student> response = new PriorityQueue<>();
        for (String event : events) {
            if (!event.startsWith("ENTER")) {
                response.poll();
                continue;
            }
            String[] split = event.split(" ");
            int id = Integer.parseInt(split[3]);
            double cgpa = Double.parseDouble(split[2]);
            Student student = new Student(id, split[1], cgpa);
            response.add(student);
        }
        return response.stream().sorted().toList();
    }
}

public class ServeStudents {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();

    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());
        List<String> events = new ArrayList<>();

        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }

        List<Student> students = priorities.getStudents(events);

        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st : students) {
                System.out.println(st.getName());
            }
        }
    }
}
