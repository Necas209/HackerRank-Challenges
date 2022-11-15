import numpy as np

def main() -> None:
    n, _ = map(int, input().split())
    arr: np.ndarray = np.array([input().strip().split() for _ in range(n)], int)
    print(arr.mean(axis=1))
    print(arr.var(axis=0))
    print(np.around(arr.std(), 11))
    
if __name__ == '__main__':
    main()