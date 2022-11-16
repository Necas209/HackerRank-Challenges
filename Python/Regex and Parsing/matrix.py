import re


def main() -> None:
    n, _ = map(int, input().split())
    m = [input() for _ in range(n)]

    print(re.sub(r'\b\W+\b', ' ', ''.join(map(''.join, zip(*m)))))


if __name__ == '__main__':
    len('This is Matrix#  %!')
    main()
