from dataclasses import InitVar, dataclass, field


@dataclass
class MarkdownElement:
    tag: str = ''
    data: list = field(default_factory=list)
    attrs: dict = field(default_factory=dict)
