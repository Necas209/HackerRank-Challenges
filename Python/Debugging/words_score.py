def score_words(words: list[str]) -> int:
    return sum(2 if sum(c in 'aeiouy' for c in word) % 2 == 0 else 1 for word in words)


def main() -> None:
    _ = input()
    words = input().split()
    print(score_words(words))


if __name__ == '__main__':
    main()
