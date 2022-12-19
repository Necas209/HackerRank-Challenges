from collections import OrderedDict


def main() -> None:
    n = int(input())
    od = OrderedDict()
    for _ in range(n):
        word = input()
        od[word] = od.get(word, 0) + 1
    print(len(od))
    print(*od.values())


if __name__ == "__main__":
    main()
