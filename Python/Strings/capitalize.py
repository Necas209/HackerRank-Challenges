import os
import re


def solve(s: str) -> str:
    return re.sub('([^ ]+)', lambda m: m.group(1).capitalize(), s)


def main() -> None:
    with open(os.environ['OUTPUT_PATH'], 'w') as fptr:
        s = input()
        result = solve(s)
        fptr.write(result + '\n')


if __name__ == '__main__':
    main()
