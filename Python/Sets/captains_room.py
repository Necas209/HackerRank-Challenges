def main() -> None:
    k = int(input())
    rooms = list(map(int, input().split()))
    s = set(rooms)
    print((sum(s) * k - sum(rooms)) // (k - 1))


if __name__ == '__main__':
    main()
