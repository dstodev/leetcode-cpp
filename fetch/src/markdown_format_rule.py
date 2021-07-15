from src.markdown_element import MarkdownElement

from typing import Union


class MarkdownFormatRule:
    def __init__(self):
        pass

    def apply(self, element: Union[str, MarkdownElement]):
        pass
