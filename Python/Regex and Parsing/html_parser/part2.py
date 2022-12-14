from html.parser import HTMLParser


class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        if "\n" in data:
            print(">>> Multi-line Comment")
        else:
            print(">>> Single-line Comment")
        print(data)

    def handle_data(self, data):
        if data != "\n":
            print(">>> Data")
            print(data)


def main():
    html = ""
    for _ in range(int(input())):
        html += input().rstrip()
        html += "\n"
    parser = MyHTMLParser()
    parser.feed(html)
    parser.close()


if __name__ == "__main__":
    main()
