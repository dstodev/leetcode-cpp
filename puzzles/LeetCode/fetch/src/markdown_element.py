from dataclasses import InitVar, dataclass, field


@dataclass
class _MarkdownElement:
    tag: str = ''
    data: list = field(default_factory=list)
    attrs: dict = field(default_factory=dict)

class MarkdownElement(_MarkdownElement):
    def __init__(self, *args, **kwargs):
        super().__init__(*args)
        self.attrs.update(kwargs)
