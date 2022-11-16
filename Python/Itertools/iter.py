from itertools import combinations
from math import comb


def solutionA(n: int, lst: list[str], k: int) -> float:
    count = 0
    combs = combinations(lst, k)
    for i in combs:
        if 'a' in i:
            count += 1
    return count / comb(n, k)


def solutionB(n: int, lst: list[str], k: int) -> float:
    return sum(1 for i in combinations(lst, k) if 'a' in i) / comb(n, k)


def main() -> None:
    n = int(input())
    lst = input().split()
    k = int(input())

    print(f'{solutionA(n, lst, k)=:.3f}')
    print(f'{solutionB(n, lst, k)=:.3f}')


if __name__ == '__main__':
    main()
