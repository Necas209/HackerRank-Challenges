import numpy as np


def main() -> None:
    arr = np.array(input().split(), int)
    print(np.reshape(arr, (3, 3)))


if __name__ == '__main__':
    main()
