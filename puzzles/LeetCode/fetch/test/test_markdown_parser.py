from unittest import TestCase, skip

from src.markdown_parser import MarkdownParser


class MockMarkdownParser(MarkdownParser):
    def __init__(self):
        super().__init__()

        self.starttag = ''
        self.endtag = ''
        self.data = ''

    def handle_starttag(self, tag):
        self.starttag = tag

    def handle_endtag(self, tag):
        self.endtag = tag

    def handle_data(self, data):
        self.data = data


class TestMarkdownParser(TestCase):

    def setUp(self):
        self.mdp = MockMarkdownParser()

    def test_instance(self):
        self.assertIsNotNone(self.mdp)

    def test_base_class_instantiation(self):
        with self.assertRaises(TypeError):
            MarkdownParser()

    def test_handle_italic(self):
        md = '*some text*'
        self.mdp.feed(md)

        self.assertEqual('*', self.mdp.starttag)
        self.assertEqual('*', self.mdp.endtag)
        self.assertEqual('some text', self.mdp.data)
