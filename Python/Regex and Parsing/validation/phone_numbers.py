import re


def validate_phone_number(phone_number):
    pattern = re.compile(r'^[789]\d{9}$')
    return bool(pattern.match(phone_number))


def main():
    n = int(input())
    for _ in range(n):
        phone_number = input()
        print('YES' if validate_phone_number(phone_number) else 'NO')


if __name__ == '__main__':
    main()
