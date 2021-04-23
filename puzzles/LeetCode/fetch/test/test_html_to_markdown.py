from unittest import TestCase

from src.html_to_markdown import HtmlToMarkdown


class TestHtmlToMarkdown(TestCase):

    def setUp(self):
        self.md = HtmlToMarkdown()

    def test_convert_code_tag(self):
        html = 'This is some <code>text</code>. It has <code>code snippets</code>.'
        expected = 'This is some `text`. It has `code snippets`.'
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
        html = 'This is some<pre>text</pre>. It is<pre>preformatted</pre>.'
        expected = 'This is some\n```\ntext\n```\n. It is\n```\npreformatted\n```\n.'
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
            'This is <em>',
            'some text</em>.'
        ]
        actual = self.md.convert(html)
        expected = 'This is *some text*.'
        self.assertEqual(expected, actual)

    def test_convert_strips_tags_inside_pre_tags(self):
        html = [
            'This is<pre>',
            'some <em>text ',
            'nested</em> inside',
            '</pre><em>preformatted</em><pre>',
            'text.</pre>'
        ]
        expected = 'This is\n```\nsome text nested inside\n```\n*preformatted*\n```\ntext.\n```\n'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_tags_inside_code_tags(self):
        html = [
            'This is some ',
            '<code><em>formatted code</em></code> ',
            'text.'
        ]
        expected = 'This is some `formatted code` text.'
        actual = self.md.convert(html)
        self.assertEqual(expected, actual)

    def test_convert_strips_nested_pre_tags(self):
        html = [
            '<em>This is</em>',
            '<pre><em>some</em> ',
            '<pre><em>nested text</em></pre> ',
            '<em>to use</em></pre>. ',
            '<em>whoa</em>'
        ]
        expected = '*This is*\n```\nsome nested text to use\n```\n. *whoa*'
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
