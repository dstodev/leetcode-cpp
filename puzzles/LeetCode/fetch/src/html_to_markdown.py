from html.parser import HTMLParser

from src.markdown_element import MarkdownElement

MAP_TAG = {
    'code': '`',
    'em': '*',
    'p': '\n',
    'pre': '```',
    'strong': '**',
    'ul': '',
    'li': '- ',
    'sup': '<sup>',
}

# Not all tags have a special end token, but take priority for each that do.
MAP_ENDTAG = {
    'li': '\n',
    'sup': '</sup>',
}


class HtmlToMarkdown(HTMLParser):
    def __init__(self):
        super().__init__()

        self.current_element = None

    def convert(self, html):
        if isinstance(html, str):
            html = [html]

        self.current_element = MarkdownElement()

        for line in html:
            self.feed(line)

        return self.current_element.flatten()  # TODO: Make flatten optional

    def handle_starttag(self, tag, attrs):  # feed() callback
        new_element = MarkdownElement()
        new_element.tag = MAP_TAG[tag]
        new_element.parent = self.current_element

        self.current_element.data.append(new_element)
        self.current_element = new_element

    def handle_endtag(self, tag):  # feed() callback
        self.current_element = self.current_element.parent

    def handle_data(self, data):  # feed() callback
        data = self.sanitize(data)
        self.current_element.data.append(data)

    def sanitize(self, data):
        return data.replace(u'\xa0', ' ')
