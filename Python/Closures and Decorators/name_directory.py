def person_lister(f: callable) -> callable:
    def inner(people: list[str]) -> list[str]:
        return map(f, sorted(people, key=lambda x: int(x[2])))
    return inner


@person_lister
def name_format(person: list[str]) -> list[str]:
    return ("Mr. " if person[3] == "M" else "Ms. ") + person[0] + " " + person[1]


def main() -> None:
    people = [input().split() for i in range(int(input()))]
    print(*name_format(people), sep='\n')


if __name__ == '__main__':
    main()