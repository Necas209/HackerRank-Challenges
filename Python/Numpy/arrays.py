import numpy as np


def main() -> None:
    arr = np.array(input().split(), float)
    print(arr[::-1])


if __name__ == '__main__':
    main()
