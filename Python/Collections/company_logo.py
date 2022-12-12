from collections import Counter


def main() -> None:
    s = input()
    c = Counter(sorted(s))
    for k, v in c.most_common(3):
        print(k, v)


if __name__ == "__main__":
    main()
