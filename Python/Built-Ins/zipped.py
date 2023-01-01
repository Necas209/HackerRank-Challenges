def main() -> None:
    _, n = map(int, input().split())
    grades = [map(float, input().split()) for _ in range(n)]
    for student in zip(*grades):
        print(f'{sum(student) / len(student):.1f}')


if __name__ == "__main__":
    main()
