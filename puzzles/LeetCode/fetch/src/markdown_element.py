from dataclasses import InitVar, dataclass, field


@dataclass
class MarkdownElement:
    tag: str = ''
    data: list = field(default_factory=list)
    attrs: dict = field(default_factory=dict)
    parent: 'MarkdownElement' = None

    def __str__(self):
        return self.flatten()

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
                text += element

        return f'{self.tag}{text}{self.tag}'

    def add_data(self, data):
        self._register_parent(data)
        self.data.append(str(data))
