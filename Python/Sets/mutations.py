def main() -> None:
    _ = input()
    s = set(input().split())
    for _ in range(int(input())):
        cmd, _ = input().split()
        getattr(s, cmd)(set(input().split()))
    print(sum(map(int, s)))


if __name__ == '__main__':
    main()
