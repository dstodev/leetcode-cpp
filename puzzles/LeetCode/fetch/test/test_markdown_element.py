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

    # These following tests test the flatten() function,
    # where n = the recursion depth sub-elements within this one.
    def test_flatten_n1(self):
        me = MarkdownElement('`', ['text'])

        expected = '`text`'
        actual = me.flatten()

        self.assertEqual(expected, actual)

    def test_flatten_n2(self):
        me = MarkdownElement('`', ['text ', MarkdownElement('"', ['text2'])])

        expected = '`text "text2"`'
        actual = me.flatten()

        self.assertEqual(expected, actual)

    def test_str_calls_flatten(self):
        me = MarkdownElement('`', ['text ', MarkdownElement('"', ['text2'])])

        expected = '`text "text2"`'
        actual = str(me)

        self.assertEqual(expected, actual)

    def test_add_data(self):
        me = MarkdownElement('`', [])
        m2 = MarkdownElement('*', ['text', MarkdownElement('"', ['text2'])])

        me.add_data('text3')
        me.add_data(m2)

        expected = '`text3*text"text2"*`'
        actual = me.flatten()

        self.assertEqual(expected, actual)

    def test_parent_none(self):
        me = MarkdownElement('`', [])

        self.assertIsNone(me.parent)

    def test_parent_constructor(self):
        child = MarkdownElement('"', ['text2'])
        me = MarkdownElement('`', ['text ', child])

        self.assertEqual(me, child.parent)

    def test_parent_add_data(self):
        child = MarkdownElement('"', ['text2'])
        me = MarkdownElement('`', ['text '])

        me.add_data(child)

        self.assertEqual(me, child.parent)
