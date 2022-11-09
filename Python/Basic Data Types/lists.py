def main() -> None:
    lst = []
    n = int(input())
    for _ in range(n):
        cmd, *args = input().split()
        if cmd == 'print':
            print(lst)
        else:
            getattr(lst, cmd)(*map(int, args))


if __name__ == '__main__':
    main()
