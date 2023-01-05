def fibonacci(n: int) -> list[int]:
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b


def main() -> None:
    n = int(input())
    print([*map(lambda x: x ** 3, fibonacci(n))])


if __name__ == '__main__':
    main()
