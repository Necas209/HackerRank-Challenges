from collections import Counter

if __name__ == '__main__':
    x = int(input())
    size_count = Counter([int(i) for i in input().split()])
    n = int(input())
    total = 0
    for _ in range(n):
        size, price = map(int, input().split())
        if size in size_count and size_count[size] > 0:
            size_count[size] -= 1
            total += price
    print(total)
