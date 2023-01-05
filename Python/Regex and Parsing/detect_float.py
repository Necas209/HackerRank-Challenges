import re


def is_float(string: str) -> bool:
    return bool(re.match(r'^[-+]?[0-9]*\.[0-9]+$', string))


def main() -> None:
    t = int(input())
    for _ in range(t):
        print(is_float(input()))


if __name__ == '__main__':
    main()
