def swap_case(st: str) -> str:
    return st.swapcase()


def main() -> None:
    s = input()
    result = swap_case(s)
    print(result)


if __name__ == '__main__':
    main()