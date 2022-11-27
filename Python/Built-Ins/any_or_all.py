def main() -> None:
    _ = input() # don't need n
    lst = [*map(int, input().split())]
    print(all(map(lambda x: x > 0, lst)) and any(
        map(lambda x: str(x) == str(x)[::-1], lst)))


if __name__ == "__main__":
    main()
