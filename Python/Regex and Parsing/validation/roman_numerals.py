import re


def roman_numeral_validator(roman_numeral):
    pattern = re.compile(r'^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$')
    return bool(pattern.match(roman_numeral))


def main():
    print(roman_numeral_validator(input()))


if __name__ == "__main__":
    main()
