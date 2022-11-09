if __name__ == '__main__':
    _ = input()
    english = set(input().split())
    _ = input()
    french = set(input().split())
    # sub = english.difference(french)
    sub = english - french
    print(len(sub))
