import numpy as np


def main() -> None:
    n, m = map(int, input().split())
    a = np.array([input().split() for _ in range(n)], int)
    b = np.array([input().split() for _ in range(m)], int)
    print(a + b)
    print(a - b)
    print(a * b)
    print(a // b)
    print(a % b)
    print(a ** b)


if __name__ == "__main__":
    main()
