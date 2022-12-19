import re


def main() -> None:
    s = input()
    pattern = r'(?<=[^aeiouAEIOU])([aeiouAEIOU]{2,})(?=[^aeiouAEIOU])'
    matches = re.findall(pattern, s)
    if matches:
        print(*matches, sep='\n')
    else:
        print(-1)


if __name__ == '__main__':
    main()
