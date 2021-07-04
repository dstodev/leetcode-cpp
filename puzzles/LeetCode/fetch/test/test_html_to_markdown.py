from unittest import TestCase

from src.html_to_markdown import HtmlToMarkdown
from src.markdown_element import MarkdownElement


class TestHtmlToMarkdown(TestCase):
    def setUp(self):
        self.md = HtmlToMarkdown()

    def test_instance(self):
        self.assertIsNotNone(self.md)

    def test_convert_code_tag(self):
        html = 'This is some <code>text</code>. It has <code>code snippets</code>.'
        expected = 'This is some `text`. It has `code snippets`.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_adjacent_tags(self):
        html = '<code>Adjacent</code><code>Tags</code>'
        expected = '`Adjacent``Tags`'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_trailing_tag(self):
        html = '<em>This text has no untagged content.</em>'
        expected = '*This text has no untagged content.*'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strong_tag(self):
        html = 'This is some <strong>text</strong>. It has <strong>bold parts</strong>.'
        expected = 'This is some **text**. It has **bold parts**.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_em_tag(self):
        html = 'This is some <em>text</em>. It has <em>italic parts</em>.'
        expected = 'This is some *text*. It has *italic parts*.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strong_and_em_tags(self):
        html = 'This text has <strong>bold and <em>italic</em></strong> parts.'
        expected = 'This text has **bold and *italic*** parts.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_pre_tag(self):
        html = 'This is some <pre>text</pre>. It is <pre>preformatted</pre>.'
        expected = 'This is some ```text```. It is ```preformatted```.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_p_tag(self):
        html = '<p>This is some text.</p><p>It is written in paragraphs.</p>'
        expected = '\nThis is some text.\n\nIt is written in paragraphs.\n'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_hex_a0(self):
        html = u'This is some text.\xa0It has a non-breaking space in it.'
        expected = 'This is some text. It has a non-breaking space in it.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_accepts_lists(self):
        html = [
            'This is ',
            '<em>some text</em>.'
        ]
        expected = 'This is *some text*.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_handles_list_split_tags(self):
        html = [
            'This is <em>',
            'some text</em>.'
        ]
        expected = 'This is *some text*.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_hides_tags_inside_pre_tags(self):
        html = [
            'This is <pre><em>some text</em> nested inside</pre>',
            ' <em>preformatted</em> <pre>text.</pre>',
        ]
        expected = 'This is ```some text nested inside``` *preformatted* ```text.```'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_tags_inside_code_tags(self):
        html = 'This is some <code><em>formatted code</em></code> text.'
        expected = 'This is some `formatted code` text.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_nested_pre_tags(self):
        html = [
            '<em>This is</em> ',
            '<pre><em>some</em> ',
            '<pre><em>nested text</em></pre> ',
            '<em>to use</em></pre>. ',
            '<em>whoa</em>'
        ]
        expected = '*This is* ```some nested text to use```. *whoa*'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_nested_code_tags(self):
        html = [
            '<em>This is</em> ',
            '<code><em>some code</em> ',
            '<code><em>nested inside</em></code> ',
            '<em>other code</em></code>. ',
            '<em>whoa</em>'
        ]
        expected = '*This is* `some code nested inside other code`. *whoa*'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_list(self):
        html = [
            '<ul>',
            '<li>Item 1</li>',
            '<li>Item 2</li>',
            '</ul>'
        ]
        expected = '- Item 1\n- Item 2\n'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_preserves_sup(self):
        html = 'This is some <sup>superscript</sup>.'
        expected = html
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_preserve_tree(self):
        html = [
            '<em>This is</em> ',
            '<code><em>some code</em> ',
            '<code><em>nested inside</em></code> ',
            '<em>other code</em></code>. ',
            '<em>whoa</em>'
        ]
        expected = MarkdownElement(data=[
            MarkdownElement('*', ['This is']),
            ' ',
            MarkdownElement('`', [
                MarkdownElement('*', ['some code'], hidden=True),
                ' ',
                MarkdownElement('`', [
                    MarkdownElement('*', ['nested inside'], hidden=True)
                ], hidden=True),
                ' ',
                MarkdownElement('*', ['other code'], hidden=True)
            ]),
            '. ',
            MarkdownElement('*', ['whoa'])
        ])
        actual = self.md.convert(html, flatten=False)
        self.assertEqual(expected, actual)
