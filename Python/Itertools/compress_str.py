from itertools import groupby


def main() -> None:
    s = input()
    print(*((len([*j]), int(i)) for i, j in groupby(s)))


if __name__ == '__main__':
    main()
    