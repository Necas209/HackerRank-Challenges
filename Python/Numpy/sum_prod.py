import numpy as np


def main() -> None:
    n, _ = map(int, input().split())
    a = np.array([input().split() for _ in range(n)], int)
    print(np.prod(np.sum(a, axis=0)))


if __name__ == "__main__":
    main()
