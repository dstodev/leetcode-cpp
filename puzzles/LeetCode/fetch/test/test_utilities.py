from unittest import TestCase

import src.utilities as utilities
from src.markdown_element import MarkdownElement


class TestUtilities(TestCase):
    def test_make_md_tree_empty(self):
        expected = MarkdownElement()
        tree = utilities.make_md_tree()

        self.assertEquaL(expected, tree)
