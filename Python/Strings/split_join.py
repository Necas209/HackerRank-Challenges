def split_and_join(s: str) -> str:
    return s.replace(' ', '-')


def main() -> None:
    line = input()
    result = split_and_join(line)
    print(result)


if __name__ == '__main__':
    main()
