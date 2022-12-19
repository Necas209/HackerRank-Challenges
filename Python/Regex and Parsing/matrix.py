import re


def main() -> None:
    n, _ = map(int, input().split())
    matrix = [input() for _ in range(n)]
    print(re.compile(r"\b[^\w]+\b").sub( ' ', ''.join([''.join(z) for z in zip(*matrix)])))


if __name__ == '__main__':
    main()
