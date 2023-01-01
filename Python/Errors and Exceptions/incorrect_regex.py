import re


def main() -> None:
    n = int(input())
    for _ in range(n):
        try:
            re.compile(input())
            print(True)
        except re.error:
            print(False)


if __name__ == "__main__":
    main()
