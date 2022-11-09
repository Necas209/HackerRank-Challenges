def main() -> None:
    # Replace all ______ with rjust, ljust or center.
    n = int(input())  # This must be an odd number
    # Top Cone
    triangle = [((2 * i + 1) * 'H').center(2 * n - 1) for i in range(n)]
    print('\n'.join(triangle))
    # Pillars and Belt
    for i in range(int(2.5 * n) + 3):
        print(((3 * n * ('H' if n < i < int(1.5 * n) + 2 else ' ')).center(5 * n, 'H')).rjust(int(5.5 * n), ' '))
    # Bottom Cone
    for i in triangle[::-1]:
        print(i.rjust(6 * n - 1, ' '))


if __name__ == '__main__':
    main()
