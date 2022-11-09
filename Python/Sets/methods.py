if __name__ == '__main__':
    _ = input()
    s = set(map(int, input().split()))
    N = int(input())
    for _ in range(N):
        cmd, *args = input().split()
        getattr(s, cmd)(*map(int, args))
    print(sum(s))
