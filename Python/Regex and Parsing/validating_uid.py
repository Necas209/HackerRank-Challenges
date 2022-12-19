import re
from collections import Counter


def validate_uid(uid: str) -> bool:
        if len(uid) != 10 or re.search(r'[\W_]', uid):
                return False
        if Counter(uid).most_common()[0][1] > 1:
                return False
        if len(re.findall(r'[A-Z]', uid)) < 2 or len(re.findall(r'\d', uid)) < 3:
                return False
        return True


def main() -> None:
    for _ in range(int(input())):
        uid = input()
        print('Valid' if validate_uid(uid) else 'Invalid')


if __name__ == '__main__':
    main()