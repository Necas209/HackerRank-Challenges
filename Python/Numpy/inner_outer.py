import numpy as np


def main() -> None:
    a = np.array(list(map(int, input().split())))
    b = np.array(list(map(int, input().split())))
    print(np.inner(a, b))
    print(np.outer(a, b))


if __name__ == "__main__":
    main()
