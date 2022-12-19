from collections import namedtuple


def main() -> None:
    n = int(input())
    Student = namedtuple("Student", input().split())
    students = [Student(*input().split()) for _ in range(n)]
    print(f"{sum([int(student.MARKS) for student in students]) / n:.2f}")


if __name__ == "__main__":
    main()
