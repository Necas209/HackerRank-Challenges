import numpy as np


def main() -> None:
    n, _ = map(int, input().split())
    lst = []
    for _ in range(n):
        lst.append(list(map(int, input().split())))
    a = np.array(lst)
    print(np.max(np.min(a, axis=1)))


if __name__ == "__main__":
    main()
    