from tkinter import N


def merge_the_tools(string: str, k: int) -> None:
    for i in range(0, len(string), k):
        print(''.join(sorted({*string[i:i + k]}, key=string[i:i + k].index)))


def main() -> None:
    string, k = input(), int(input())
    merge_the_tools(string, k)


if __name__ == '__main__':
    main()
