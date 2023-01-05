import numpy as np


def main() -> None:
    n, m, _ = map(int, input().split())
    arr1 = np.array([input().split() for _ in range(n)], int)
    arr2 = np.array([input().split() for _ in range(m)], int)
    print(np.concatenate((arr1, arr2)))


if __name__ == '__main__':
    main()
