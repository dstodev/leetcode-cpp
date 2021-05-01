from dataclasses import dataclass, field


@dataclass
class MarkdownElement:
    tag: str = ''
    data: str = ''
    children: list = field(default_factory=list)
