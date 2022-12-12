def average(array: list[int]) -> float:
    s = set(array)
    return sum(s) / len(s)
    

def main():
    _ = input()
    arr = [int(s) for s in input().split()]
    result = average(arr)
    print(result)


if __name__ == '__main__':
    main()
