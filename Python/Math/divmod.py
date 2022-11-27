def main() -> None:
    a, b = int(input()), int(input())
    print(a // b, a % b, divmod(a, b), sep='\n')


if __name__ == '__main__':
    main()