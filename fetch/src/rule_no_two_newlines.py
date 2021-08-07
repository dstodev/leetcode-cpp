from src.markdown_format_rule import MarkdownFormatRule, MarkdownElement


class RuleNoTwoNewlines(MarkdownFormatRule):
    def apply(self, element: MarkdownElement):
        # Depth-first iteration of the element tree, where duplicate newlines are stripped?
        pass
