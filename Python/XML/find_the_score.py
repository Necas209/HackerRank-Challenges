# noinspection PyPep8Naming
import xml.etree.ElementTree as etree


def get_attr_number(node: etree.Element) -> int:
    return sum(len(node.attrib) for node in node.iter())


def main() -> None:
    n = int(input())
    xml = ''.join(input() for _ in range(n))
    tree = etree.ElementTree(etree.fromstring(xml))
    root = tree.getroot()
    print(get_attr_number(root))


if __name__ == '__main__':
    main()
