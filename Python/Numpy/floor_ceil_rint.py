import numpy as np


def main() -> None:
    np.set_printoptions(legacy='1.13')

    lst = list(map(float, input().split()))
    a = np.array(lst)

    print(np.floor(a))
    print(np.ceil(a))
    print(np.rint(a))


if __name__ == "__main__":
    main()
