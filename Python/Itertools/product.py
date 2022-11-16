from itertools import product


def main() -> None:
    lstA = map(int, input().split())
    lstB = map(int, input().split())
    print(*product(lstA, lstB))


if __name__ == '__main__':
    main()