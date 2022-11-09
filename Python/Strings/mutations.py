def mutate_string(st: str, pos: int, ch: str) -> str:
    return st[:pos] + ch + st[pos + 1:]


def main() -> None:
    s = input()
    i, c = input().split()
    s_new = mutate_string(s, int(i), c)
    print(s_new)


if __name__ == '__main__':
    main()
