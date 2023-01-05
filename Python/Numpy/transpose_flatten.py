import numpy as np


def main() -> None:
    n, _ = map(int, input().split())
    lst = [list(map(int, input().split())) for _ in range(n)]
    arr = np.array(lst)
    print(arr.T)
    print(arr.flatten())


if __name__ == '__main__':
    main()
