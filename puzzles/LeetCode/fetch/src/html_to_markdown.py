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

# Tags which disable formatting
PREFORMATTED_TAG = {
    '`',
    '```'
}


class HtmlToMarkdown(HTMLParser):
    def __init__(self):
        super().__init__()
        self.current_element = None

    def convert(self, html, flatten=True):
        if isinstance(html, str):
            html = [html]

        self.current_element = MarkdownElement()

        for line in html:
            self.feed(line)

        if flatten:
            return self.current_element.flatten()
        else:
            return self.current_element

    def handle_starttag(self, tag, attrs):  # feed() callback
        new_element = MarkdownElement()
        try:
            new_element.tag = [MAP_TAG[tag], MAP_ENDTAG[tag]]
        except KeyError:
            new_element.tag = MAP_TAG[tag]

        self.register_hidden(new_element)

        self.current_element.add_data(new_element)
        self.current_element = new_element

    def register_hidden(self, element):
        if self.current_element.hidden \
                or self.current_element.tag in PREFORMATTED_TAG:
            element.hidden = True

    def handle_endtag(self, tag):  # feed() callback
        self.current_element = self.current_element.parent

    def handle_data(self, data):  # feed() callback
        data = self.sanitize(data)
        self.current_element.data.append(data)

    def sanitize(self, data):
        return data.replace(u'\xa0', ' ')
