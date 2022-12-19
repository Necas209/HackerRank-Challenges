import re


def main() -> None:
    n = int(input())
    for _ in range(n):
        cc_number = input()
        repeats = re.match(r'.*(\d)\1{3,}.*', cc_number.replace('-', ''))
        valid_cc = re.match(r'^[456]\d{3}(-?\d{4}){3}$', cc_number)
        print('Valid' if not repeats and valid_cc else 'Invalid')


if __name__ == '__main__':
    main()
    