from html.parser import HTMLParser

from src.markdown_element import MarkdownElement

MAP_TAG = {
    'code': '`',
    'em': '*',
    'p': '\n',
    'pre': '\n```\n',
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
    _tags_to_disable_formatting = {'pre', 'code'}

    def __init__(self):
        super().__init__()

        self.markdown = []
        self.token = None

        self.disablers = 0

    def _handle_disabler_increment(self, tag):
        if tag in self._tags_to_disable_formatting:
            self.disablers += 1

    def _handle_disabler_decrement(self, tag):
        if tag in self._tags_to_disable_formatting:
            self.disablers -= 1

    def convert(self, html):
        if isinstance(html, str):
            html = [html]

        self.markdown = []
        self.token = MarkdownElement()

        for line in html:
            self.feed(line)

        self.commit_token()

        return self.markdown

    def commit_token(self):
        if self.token:
            self.markdown.append(self.token)
            self.token = MarkdownElement()

    def handle_starttag(self, tag, attrs):
        if self.disablers == 0:
            self.commit_token()
            try:
                self.token.tag = MAP_TAG[tag]
            except:
                raise

        self._handle_disabler_increment(tag)

    def handle_endtag(self, tag):
        self._handle_disabler_decrement(tag)

        if self.disablers == 0:
            self.commit_token()

    def handle_data(self, data):
        data = data.replace(u'\xa0', ' ')
        self.token.data = data
