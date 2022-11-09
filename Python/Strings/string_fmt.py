def print_formatted(number: int) -> None:
    n = len(bin(number)[2:])
    for i in range(1, number + 1):
        print(f'{i: >{n - 1}}'
              f'{oct(i)[2:]: >{n}}'
              f'{hex(i)[2:].upper(): >{n}}'
              f'{bin(i)[2:]: >{n}}')


def main() -> None:
    n = int(input())
    print_formatted(n)


if __name__ == '__main__':
    main()
