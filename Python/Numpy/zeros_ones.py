import numpy as np


def main() -> None:
    dims = tuple(map(int, input().split()))
    print(np.zeros(dims, dtype=np.int))
    print(np.ones(dims, dtype=np.int))


if __name__ == "__main__":
    main()
