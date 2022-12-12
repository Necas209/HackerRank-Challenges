def main() -> None:
    _ = input()
    arr = list(map(int, input().split()))
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))

    happiness = sum((i in a) - (i in b) for i in arr)
    print(happiness)


if __name__ == "__main__":
    main()
