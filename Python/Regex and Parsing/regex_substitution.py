import re


def main() -> None:
    n = int(input())
    for _ in range(n):
        line = input()
        line = re.sub(r"(?<= )(&&|\|\|)(?= )", lambda x: "and" if x.group() == "&&" else "or", line)
        print(line)


if __name__ == "__main__":
    main()
