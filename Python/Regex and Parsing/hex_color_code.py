import re


def main() -> None:
    n = int(input())
    for _ in range(n):
        line = input()
        match = re.findall(r'(?<!^)(#([0-9A-Fa-f]{3}){1,2})', line)
        if match:
            print(*[m[0] for m in match], sep='\n')


if __name__ == '__main__':
    main()
