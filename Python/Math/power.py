def main() -> None:
    a, b, m = int(input()), int(input()), int(input())
    print(pow(a, b), pow(a, b, m), sep='\n')


if __name__ == '__main__':
    main()