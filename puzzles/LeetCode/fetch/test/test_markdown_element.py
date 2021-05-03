from unittest import TestCase

from src.markdown_element import MarkdownElement


class TestMarkdownElement(TestCase):

    def test_default_instance(self):
        me = MarkdownElement()
        self.assertEqual('', me.tag)
        self.assertEqual('', me.data)
        self.assertEqual([], me.children)
        self.assertFalse(me.hidden)

    def test_nondefault_instance(self):
        me = MarkdownElement('tag', 'data', ['children'], True)
        self.assertEqual('tag', me.tag)
        self.assertEqual('data', me.data)
        self.assertEqual(['children'], me.children)
        self.assertTrue(me.hidden)
