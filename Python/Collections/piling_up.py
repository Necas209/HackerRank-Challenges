from collections import deque

def main() -> None:
    t = int(input())
    for _ in range(t):
        _ = input()
        d = deque(map(int, input().split()))
        t = max(d[0], d[-1])
        while len(d) > 1:
            if d[0] >= d[-1] and d[0] <= t:
                t = d.popleft()
            elif d[-1] >= d[0] and d[-1] <= t:
                t = d.pop()
            else:
                print("No")
                break
        else:
            print("Yes")


if __name__ == "__main__":
    main()
