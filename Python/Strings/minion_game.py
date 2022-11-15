def minion_game(s: str) -> None:
    vowels = 'AEIOU'
    kevin = sum(len(s) - i for i, c in enumerate(s) if c in vowels)
    stuart = sum(len(s) - i for i, c in enumerate(s) if c not in vowels)
    if kevin > stuart:
        print('Kevin', kevin)
    elif kevin < stuart:
        print('Stuart', stuart)
    else:
        print('Draw')


def main()  -> None:
    s = input()
    minion_game(s)


if __name__ == '__main__':
    main()