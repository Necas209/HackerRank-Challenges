def main() -> None:
    s = input()
    lst = [False] * 5
    for c in s:
        lst[0] |= c.isalnum()
        lst[1] |= c.isalpha()
        lst[2] |= c.isdigit()
        lst[3] |= c.islower()
        lst[4] |= c.isupper()
        if all(lst):
            break
    [print(r) for r in lst]


if __name__ == '__main__':
    main()
