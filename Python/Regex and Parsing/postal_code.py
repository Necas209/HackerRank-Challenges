import re

if __name__ == '__main__':
    P = input()
    print(bool(re.match(r'^[1-9]\d{5}$', P))
          and len(re.findall(r'(?=(\d)\d\1)', P)) < 2)
