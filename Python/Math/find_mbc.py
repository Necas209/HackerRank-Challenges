import math


def main() -> None:
    ab = int(input())
    bc = int(input())

    print(f'{round(math.degrees(math.atan2(ab, bc)))}{chr(176)}')


if __name__ == '__main__':
    main()