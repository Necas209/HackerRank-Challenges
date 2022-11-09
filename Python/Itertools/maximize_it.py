from itertools import product, starmap

if __name__ == '__main__':
    k, m = map(int, input().split())
    sq = [map(lambda x: int(x) ** 2, input().split()[1:])
          for _ in range(k)]
    s_max = max(starmap(lambda *x: sum(x) % m, product(*sq)))
    print(s_max)
