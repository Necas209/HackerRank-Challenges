import numpy as np


def main() -> None:
    n = int(input())
    arr_a = np.array([input().split() for _ in range(n)], int)
    arr_b = np.array([input().split() for _ in range(n)], int)
    print(np.dot(arr_a, arr_b))


if __name__ == '__main__':
    main()
