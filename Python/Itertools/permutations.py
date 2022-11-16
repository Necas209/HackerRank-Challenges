from itertools import permutations


def main() -> None:
    s, k = input().split()
    k = int(k)

    print(*(''.join(i) for i in permutations(sorted(s), k)), sep='\n')


if __name__ == '__main__':
    main()