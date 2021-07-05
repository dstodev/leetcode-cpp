from unittest import TestCase, skip

from src.markdown_formatter import MarkdownFormatter
from src.markdown_element import MarkdownElement


class TestMarkdownFormatter(TestCase):

    def setUp(self):
        self.mdf = MarkdownFormatter()

    def test_instance(self):
        self.assertIsNotNone(self.mdf)

    def test_format_asserts_no_more_than_one_empty_line(self):
        md = MarkdownElement(data=[
            'This\n',
            '\n',
            'is\n',
            '\n',
            '\n'
            'a\n',
            '\n',
            '\n',
            '\n',
            'test'
        ])
        expected = MarkdownElement(data=[
            'This\n',
            '\n',
            'is\n',
            '\n',
            'a\n',
            '\n',
            'test'
        ])
        actual = self.mdf.format(md)
        self.assertEqual(expected, actual)

    @skip('Not supporting headings yet')
    def test_format_heading_spacing(self):
        md = '\n'.join((
            'some text',
            '# heading 1',
            'more text'
        ))
        expected = '\n'.join((
            'some text',
            '',
            '# heading 1',
            '',
            'more text'
        ))
        actual = self.mdf.format(md)
        self.assertEqual(expected, actual)

    @skip('Not supporting headings yet')
    def test_format_all_headings(self):
        md = '\n'.join((
            'some text',
            '#heading 1',
            '##heading 2',
            '###heading 3',
            'more text',
            '####heading 4',
            '#####heading 5',
            '######heading 6',
            'last text'
        ))
        expected = '\n'.join((
            'some text',
            '',
            '# heading 1',
            '',
            '## heading 2',
            '',
            '### heading 3',
            '',
            'more text',
            '',
            '#### heading 4',
            '',
            '##### heading 5',
            '',
            '###### heading 6',
            '',
            'last text'
        ))
        actual = self.mdf.format(md)
        self.assertEqual(expected, actual)
