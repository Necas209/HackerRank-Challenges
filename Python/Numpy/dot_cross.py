import numpy as np


def main() -> None:
    n = int(input())
    arrA = np.array([input().strip().split() for _ in range(n)], int)
    arrB = np.array([input().strip().split() for _ in range(n)], int)
    print(np.dot(arrA, arrB))
    
if __name__ == '__main__':
    main()