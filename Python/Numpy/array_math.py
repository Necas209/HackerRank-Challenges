import numpy as np


def main() -> None:
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    b = [list(map(int, input().split())) for _ in range(n)]
    a = np.array(a)
    b = np.array(b)

    print(a + b)
    print(a - b)
    print(a * b)
    print(a // b)
    print(a % b)
    print(a ** b)


if __name__ == "__main__":
    main()
