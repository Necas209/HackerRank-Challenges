import numpy as np


def main() -> None:
    np.set_printoptions(legacy='1.13')
    a = np.array(input().split(), float)
    print(np.floor(a))
    print(np.ceil(a))
    print(np.rint(a))


if __name__ == "__main__":
    main()
