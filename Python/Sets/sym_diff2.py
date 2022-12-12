def main() -> None:
    _ = input()
    arr = {int(s) for s in input().split()}
    _ = input()
    arr2 = {int(s) for s in input().split()}
    print(*sorted(arr.symmetric_difference(arr2)), sep='\n')


if __name__ == '__main__':
    main()
