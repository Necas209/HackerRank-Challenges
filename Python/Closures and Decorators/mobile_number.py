from typing import Callable


def wrapper(f: Callable[[list[str]], str]) -> Callable[[list[str]], str]:
    def fun(lst: list[str]) -> str:
        f(["+91 " + c[-10:-5] + " " + c[-5:] for c in lst])

    return fun


@wrapper
def sort_phone(s: list[str]) -> None:
    print(*sorted(s), sep='\n')


def main() -> None:
    n = int(input())
    lst = [input() for _ in range(n)]
    sort_phone(lst)


if __name__ == '__main__':
    main()
