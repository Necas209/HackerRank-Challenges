import numpy as np


def main() -> None:
    n, m = map(int, input().split())
    np.set_printoptions(legacy='1.13')
    print(np.eye(n, m))


if __name__ == "__main__":
    main()
