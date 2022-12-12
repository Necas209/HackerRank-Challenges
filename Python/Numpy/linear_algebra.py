import numpy as np


def main() -> None:
    n = int(input())
    a = np.array([[*map(float, input().split())] for _ in range(n)])
    print(np.round(np.linalg.det(a), 2))
        


if __name__ == "__main__":
    main()
    