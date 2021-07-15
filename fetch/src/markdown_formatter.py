from src.markdown_element import MarkdownElement
from src.markdown_format_rule import MarkdownFormatRule

from typing import List


class MarkdownFormatter:
    def __init__(self):
        self.rules: List[MarkdownFormatRule] = []

    def format(self, markdown_root: MarkdownElement):
        for datum in markdown_root.data:
            for rule in self.rules:
                rule.apply(datum)
