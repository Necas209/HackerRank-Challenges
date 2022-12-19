import numpy as np


def main() -> None:
    dims = tuple(map(int, input().split()))
    print(np.zeros(dims, dtype=np.int32))
    print(np.ones(dims, dtype=np.int32))


if __name__ == "__main__":
    main()
    