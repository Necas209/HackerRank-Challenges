def main() -> None:
    a = set(map(int, input().split()))
    n = int(input())
    for _ in range(n):
        b = set(map(int, input().split()))
        if not a.issuperset(b):
            print(False)
            return
    print(True)


if __name__ == '__main__':
    main()
