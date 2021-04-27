import abc
import re

span_delimiters = (
    '*',
)

block_delimiters = (
    '```'
)


class MarkdownParser(metaclass=abc.ABCMeta):
    def __init__(self):
        pass

    @abc.abstractmethod
    def handle_starttag(self, tag):
        raise NotImplementedError

    @abc.abstractmethod
    def handle_endtag(self, tag):
        raise NotImplementedError

    @abc.abstractmethod
    def handle_data(self, data):
        raise NotImplementedError

    def feed(self, markdown):
        tokens = re.split(f'([{"".join(span_delimiters)}])', markdown)[1:-1]

        for token in tokens:
            if token in span_delimiters:
                self.handle_starttag(token)
