from dataclasses import InitVar, dataclass, field
from typing import Union, List


@dataclass(eq=False)
class MarkdownElement:
    tag: Union[List[str], str] = ''
    data: list = field(default_factory=list)
    parent: 'MarkdownElement' = None
    hidden: bool = False

    def __str__(self):
        return self.flatten()

    def __eq__(self, other):
        if isinstance(other, type(self)):
            eq_tag = self.tag == other.tag
            eq_data = self.data == other.data

            # Assert parents have the same contents, but do not care about instance equality
            try:
                eq_parent = self.parent.flatten() == other.parent.flatten()
            except AttributeError:
                eq_parent = (self.parent is None and other.parent is None)

            eq_hidden = self.hidden == other.hidden

            return eq_tag and eq_data and eq_parent and eq_hidden

        else:
            return False

    def __post_init__(self):
        for element in self.data:
            self._register_parent(element)

    def _register_parent(self, element):
        try:
            element.parent = self
        except AttributeError:
            pass

    @property
    def is_text_only(self):
        # If the element only has text, it will never have a tag.
        return (bool(self.data)
                and not bool(self.tag))

    def flatten(self):
        text = ''
        for element in self.data:
            try:
                text += element.flatten()
            except AttributeError:
                # element is a string
                text += element

        return self.add_tags(text)

    def add_tags(self, text):
        if self.hidden:
            tag = ''
        else:
            tag = self.tag

        if isinstance(tag, str):
            return f'{tag}{text}{tag}'
        else:
            return f'{tag[0]}{text}{tag[1]}'

    def add_data(self, data):
        self._register_parent(data)
        self.data.append(data)
