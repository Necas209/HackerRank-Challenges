import string


def print_rangoli(size: int) -> None:
    alpha = ' ' + string.ascii_lowercase
    for i in range(size, 0, -1):
        print('-'.join(alpha[size:i:-1] + alpha[i:size + 1]).center((size * 4) - 3, '-'))
    for i in range(0, size - 1):
        print('-'.join(alpha[size:i + 2:-1] + alpha[i + 2:size + 1]).center((size * 4) - 3, '-'))


def main() -> None:
    n = int(input())
    print_rangoli(n)


if __name__ == '__main__':
    main()
