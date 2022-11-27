def main() -> None:
    n, _ = map(int, input().split())
    arr = [[*map(int, input().split())] for _ in range(n)]
    k = int(input())
    arr.sort(key=lambda x: x[k])
    for row in arr:
        print(*row)


if __name__ == '__main__':
    main()
