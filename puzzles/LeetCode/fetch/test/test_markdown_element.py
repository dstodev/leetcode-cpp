from unittest import TestCase

from src.markdown_element import MarkdownElement


class TestMarkdownElement(TestCase):

    def test_instance(self):
        me = MarkdownElement('tag', 'data', ['children'])
        self.assertEqual('tag', me.tag)
        self.assertEqual('data', me.data)
        self.assertEqual(['children'], me.children)
