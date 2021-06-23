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

    def test_is_text_only_empty(self):
        me = MarkdownElement()
        self.assertFalse(me.is_text_only)

    def test_is_text_only_text_only(self):
        me = MarkdownElement(data=['stuff'])
        self.assertTrue(me.is_text_only)

    def test_is_text_only_has_tag(self):
        me = MarkdownElement('tag')
        self.assertFalse(me.is_text_only)

    def test_is_text_only_has_tag_and_text(self):
        me = MarkdownElement('tag', ['stuff'])
        self.assertFalse(me.is_text_only)
