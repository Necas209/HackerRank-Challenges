from itertools import combinations_with_replacement


def main() -> None:
    s, k = input().split()
    k = int(k)

    print(*(''.join(i) for i in combinations_with_replacement(sorted(s), k)), sep='\n')


if __name__ == '__main__':
    main()
    