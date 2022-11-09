import re


def count_substring(st: str, sub_str: str) -> int:
    return sum(1 for _ in re.finditer(f'(?={sub_str})', st))
    # count = it = 0
    # while True:
    #     it = string.find(sub_string, it) + 1
    #     if it == 0:
    #         return count
    #     else:
    #         count += 1


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    print(count_substring(string, sub_string))
