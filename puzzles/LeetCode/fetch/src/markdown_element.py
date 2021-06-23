from dataclasses import InitVar, dataclass, field


@dataclass
class MarkdownElement:
    tag: str = ''
    data: list = field(default_factory=list)
    attrs: dict = field(default_factory=dict)

    @property
    def is_text_only(self):
        # If the element only has text, it will never have a tag.
        return (bool(self.data)
                and not bool(self.tag))
