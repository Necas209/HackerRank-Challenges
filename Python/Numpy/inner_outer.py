import numpy as np


def main() -> None:
    a = np.array(input().split(), int)
    b = np.array(input().split(), int)
    print(np.inner(a, b))
    print(np.outer(a, b))


if __name__ == "__main__":
    main()
