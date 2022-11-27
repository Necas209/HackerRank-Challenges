import re


def main() -> None:
    s = input()
    m = re.search(r'([^\W_])\1+', s)
    print(m.group(1) if m else -1)


if __name__ == "__main__":
    main()
