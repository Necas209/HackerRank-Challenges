import numpy as np


def main() -> None:
    p = list(map(float, input().split()))
    x = float(input())

    print(np.polyval(p, x))


if __name__ == "__main__":
    main()
