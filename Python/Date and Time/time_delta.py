from datetime import datetime


def time_delta(t1: datetime, t2: datetime) -> int:
    return int(abs((t1 - t2).total_seconds()))
    

def main() -> None:
    t = int(input())
    for _ in range(t):
        t1 = datetime.strptime(input(), '%a %d %b %Y %H:%M:%S %z')
        t2 = datetime.strptime(input(), '%a %d %b %Y %H:%M:%S %z')
        print(time_delta(t1, t2))


if __name__ == '__main__':
    main()