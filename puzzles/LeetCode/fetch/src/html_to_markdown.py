from html.parser import HTMLParser

map = {
    'code': '`',
    'em': '*',
    'p': '\n',
    'pre': '\n```\n',
    'strong': '**',
    'ul': '',
    'li': '- ',
    'sup': '<sup>',
}

# Not all tags have a special end tag.
map_endtag = {
    'li': '\n',
    'sup': '</sup>',
}


class HtmlToMarkdown(HTMLParser):
    _tags_to_disable_formatting = {'pre', 'code'}

    def __init__(self):
        super().__init__()

        self.markdown = ''
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

        self.markdown = ''

        for line in html:
            self.feed(line)

        return self.markdown

    def handle_starttag(self, tag, attrs):
        if self.disablers == 0:
            try:
                self.markdown += map[tag]
            except:
                raise

        self._handle_disabler_increment(tag)

    def handle_endtag(self, tag):
        self._handle_disabler_decrement(tag)

        if self.disablers == 0:
            try:
                self.markdown += map_endtag[tag]

            except KeyError:
                try:
                    self.markdown += map[tag]
                except:
                    raise

    def handle_data(self, data):
        data = data.replace(u'\xa0', ' ')
        self.markdown += data
