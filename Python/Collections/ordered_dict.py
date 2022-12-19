from collections import OrderedDict


def main() -> None:
    n = int(input())
    od = OrderedDict()
    for _ in range(n):
        item, _, price = input().rpartition(" ")
        od[item] = od.get(item, 0) + int(price)
    print(*[" ".join([item, str(price)]) for item, price in od.items()], sep="\n")


if __name__ == "__main__":
    main()
