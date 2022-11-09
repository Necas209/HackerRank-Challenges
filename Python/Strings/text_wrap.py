import textwrap


def wrap(string: str, max_width: int) -> str:
    return '\n'.join(textwrap.wrap(string, max_width))


def main() -> None:
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)


if __name__ == '__main__':
    main()
