import email.utils as eu
import re


def is_valid_email(address: str) -> bool:
    _, address = eu.parseaddr(address)
    return bool(re.match(r'^[a-zA-Z][\w\-.]*@[a-zA-Z]+\.[a-zA-Z]{1,3}$', address))


def main():
    n = int(input())
    for _ in range(n):
        email_address = input()
        if is_valid_email(email_address):
            print(email_address)


if __name__ == '__main__':
    main()
