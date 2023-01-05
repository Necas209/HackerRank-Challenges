import numpy as np


def main() -> None:
    p = np.array(input().split(), float)
    x = float(input())
    print(np.polyval(p, x))


if __name__ == "__main__":
    main()
