from html.parser import HTMLParser

from src.markdown_element import MarkdownElement

MAP_TAG = {
    'code': '`',
    'em': '*',
    'p': 'p',
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
    _tags_to_disable_formatting = {'pre', 'code'}

    def __init__(self):
        super().__init__()

        self.element_stack = []
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

        self.element_stack = []

        for line in html:
            self.feed(line)

        if self.has_element():
            self.commit_current_element()

        return self.markdown

    def handle_starttag(self, tag, attrs):
        tag_md = MAP_TAG[tag]

        if self.current_element_has_content():
            self.commit_current_element()

        # Current element is now the parent
        index = len(self.current_element().children)
        self.current_element().tag = tag_md

    def make_new_element(self):
        self.element_stack.append(MarkdownElement())

    def has_element(self):
        try:
            self.current_element()
            return True
        except IndexError:
            return False

    def current_element(self):
        return self.element_stack[-1]

    # TODO: Don't look at default state. Shouldn't matter.
    # TODO: Or maybe it's fine?
    def current_element_has_content(self):
        try:
            element = self.current_element()
            return (element != MarkdownElement())
        except IndexError:
            return False

    def current_element_has_tag(self):
        return bool(self.current_element().tag)

    def commit_current_element(self):
        element = self.element_stack.pop()

        if self.has_element():
            # Popped from element stack, so current element is now the parent
            self.current_element().children.append(element)
        else:
            self.markdown.append(element)
            self.make_new_element()

    def handle_endtag(self, tag):
        assert MAP_TAG[tag] == self.current_element().tag
        self.commit_current_element()

    def handle_data(self, data):
        self.make_new_element_if_empty()

        data = data.replace(u'\xa0', ' ')
        self.current_element().data = data
