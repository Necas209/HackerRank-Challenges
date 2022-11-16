from itertools import combinations


def main() -> None:
    s, k = input().split()
    k = int(k)

    for i in range(1, k + 1):
        print(*(''.join(j) for j in combinations(sorted(s), i)), sep='\n')


if __name__ == '__main__':
    main()
