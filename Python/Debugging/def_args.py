from typing import Optional, Protocol


class Stream(Protocol):
    def get_next(self) -> int:
        ...


class EvenStream:
    def __init__(self) -> None:
        self.current = 0

    def get_next(self) -> int:
        to_return = self.current
        self.current += 2
        return to_return


class OddStream:
    def __init__(self) -> None:
        self.current = 1

    def get_next(self) -> int:
        to_return = self.current
        self.current += 2
        return to_return


def print_from_stream(n: int, stream: Optional[Stream] = None) -> None:
    if not stream:
        stream = EvenStream()
    for _ in range(n):
        print(stream.get_next())


def main():
    queries = int(input())
    for _ in range(queries):
        stream_name, n = input().split()
        n = int(n)
        if stream_name == "even":
            print_from_stream(n)
        else:
            print_from_stream(n, OddStream())


if __name__ == "__main__":
    main()
