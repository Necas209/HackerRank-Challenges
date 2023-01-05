import re


def main() -> None:
    s = input()
    k = input()
    m = [*re.finditer(r'(?=({}))'.format(k), s)]
    if m:
        print(*[(match.start(1), match.end(1) - 1) for match in m], sep='\n')
    else:
        print((-1, -1))


if __name__ == '__main__':
    main()
