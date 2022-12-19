import re


def main() -> None:
    s = input()
    print(*re.split(r'[,.]', s), sep='\n')


if __name__ == '__main__':
    main()
    