def main() -> None:
    n, m = map(int, input().split())
    for i in range(n):
        if i == n // 2:
            print('WELCOME'.center(m, '-'))
        else:
            k = i if i < n // 2 else n - i - 1
            print(('.|.' * (2 * k + 1)).center(m, '-'))


if __name__ == '__main__':
    main()
