from collections import deque


def main() -> None:
    n = int(input())
    d = deque()
    for _ in range(n):
        command, *args = input().split()
        getattr(d, command)(*args)
    print(*d)


if __name__ == "__main__":
    main()
