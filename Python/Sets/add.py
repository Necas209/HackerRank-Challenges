def main() -> None:
    s = set()
    n = int(input())
    for _ in range(n):
        s.add(input())
    print(len(s))


if __name__ == "__main__":
    main()
