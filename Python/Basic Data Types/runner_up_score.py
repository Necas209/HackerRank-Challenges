def main() -> None:
    _ = int(input())
    arr = map(int, input().split())
    arr = sorted(arr, reverse=True)
    try:
        print(next(x for x in arr if x != arr[0]))
    except StopIteration:
        print(arr[0])


if __name__ == '__main__':
    main()
