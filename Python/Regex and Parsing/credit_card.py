import re

if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        cc_number = input()
        repeats = re.match(R'.*(\d)\1{3,}.*', cc_number.replace('-', ''))
        valid_cc = re.match(R'^[456]\d{3}(-?\d{4}){3}$', cc_number)
        print('Valid' if not repeats and valid_cc else 'Invalid')
