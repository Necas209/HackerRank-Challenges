from collections import defaultdict


def main() -> None:
    n, m = map(int, input().split())
    d = defaultdict(list)
    for i in range(1, n + 1):
        d[input()].append(i)
    for _ in range(m):
        print(*d[input()] or [-1])


if __name__ == "__main__":
    main()
