from fractions import Fraction
from functools import reduce


def product(fracs: list[Fraction]) -> tuple[int, int]:
    t = reduce(lambda x, y: x * y, fracs)
    return t.numerator, t.denominator


def main():
    n = int(input())
    fracs = [Fraction(*map(int, input().split())) for _ in range(n)]
    result = product(fracs)
    print(*result)


if __name__ == '__main__':
    main()
