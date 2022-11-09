def main() -> None:
    grades = []
    grade_set = set()
    n = int(input())
    for i in range(n):
        name = input()
        grade = float(input())
        grades.append([name, grade])
        grade_set.add(grade)
    second_lowest = sorted(grade_set)[1]
    [print(name) for name in sorted(name for name, score in grades
                                    if score == second_lowest)]


if __name__ == '__main__':
    main()
