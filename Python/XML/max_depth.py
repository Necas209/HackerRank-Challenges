import xml.etree.ElementTree as etree

maxdepth = 0


def depth(elem: etree.Element, level: int) -> None:
    global maxdepth
    level += 1
    if level > maxdepth:
        maxdepth += 1
    for child in elem:
        depth(child, level)


def main() -> None:
    n = int(input())
    xml = ""
    for _ in range(n):
        xml += input() + "\n"
    tree = etree.ElementTree(etree.fromstring(xml))
    depth(tree.getroot(), -1)
    print(maxdepth)


if __name__ == '__main__':
    main()
