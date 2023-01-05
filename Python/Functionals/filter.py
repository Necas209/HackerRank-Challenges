import re


def is_valid_email(s: str) -> bool:
    return bool(re.match(r'^[a-zA-Z0-9-_]+@[a-zA-Z0-9]+\.[a-zA-Z]{1,3}$', s))


def main() -> None:
    n = int(input())
    lst = [input() for _ in range(n)]
    emails = [*filter(is_valid_email, lst)]
    emails.sort()
    print(emails)


if __name__ == '__main__':
    main()
