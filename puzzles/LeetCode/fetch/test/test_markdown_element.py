from unittest import TestCase

from src.markdown_element import MarkdownElement


class TestMarkdownElement(TestCase):
    def test_default_instance(self):
        me = MarkdownElement()
        self.assertEqual('', me.tag)
        self.assertEqual([], me.data)
        self.assertEqual({}, me.attrs)

    def test_nondefault_instance(self):
        me = MarkdownElement('tag', ['data'], {'hidden': True})
        self.assertEqual('tag', me.tag)
        self.assertEqual(['data'], me.data)
        self.assertEqual({'hidden': True}, me.attrs)

    def test_instance_with_attrs_as_kwargs(self):
        me = MarkdownElement('tag', ['data'], hidden=True)
        self.assertEqual('tag', me.tag)
        self.assertEqual(['data'], me.data)
        self.assertEqual({'hidden': True}, me.attrs)
