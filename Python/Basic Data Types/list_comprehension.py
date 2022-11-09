from itertools import product


def main() -> None:
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

    print([list(p) for p in product(*[range(x + 1),
                                      range(y + 1),
                                      range(z + 1)])
           if sum(p) != n])

    print([[i, j, k] for i in range(x + 1)
           for j in range(y + 1)
           for k in range(z + 1)
           if i + j + k != n])


if __name__ == '__main__':
    main()
