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
    def __init__(self):
        super().__init__()

        self.element_stack = []

    def convert(self, html):
        if isinstance(html, str):
            html = [html]

        self.element_stack = [MarkdownElement()]

        for line in html:
            self.feed(line)

        return self.current_element().data

    def has_element(self):
        try:
            self.current_element()
            return True
        except IndexError:
            return False

    def current_element(self):
        return self.element_stack[-1]

    def handle_starttag(self, tag, attrs):
        tag_md = MAP_TAG[tag]

        if self.current_element_has_content():
            self.push_new_element()

        self.current_element().tag = tag_md

    def push_new_element(self):
        self.element_stack.append(MarkdownElement())

    # TODO: Don't look at default state. Shouldn't matter.
    # TODO: Or maybe it's fine?
    def current_element_has_content(self):
        try:
            element = self.current_element()
            return (element != MarkdownElement())
        except IndexError:
            return False

    def handle_endtag(self, tag):
        if self.current_element_has_tag():
            assert MAP_TAG[tag] == self.current_element().tag
        else:
            raise ValueError(f'Found end tag "{tag}" without start tag!')

        self.commit_current_element()

    def current_element_has_tag(self):
        return bool(self.current_element().tag)

    def commit_current_element(self):
        element = self.element_stack.pop()

        # Popped from element stack, so current element is now the parent
        self.current_element().data.append(element)

    def handle_data(self, data):
        data = data.replace(u'\xa0', ' ')
        self.current_element().data.append(data)
