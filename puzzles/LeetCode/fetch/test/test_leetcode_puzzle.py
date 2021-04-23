from pathlib import Path
from unittest import TestCase, main, mock

import requests_html
from src.leetcode_puzzle import LeetCodePuzzle
from src.take_snapshot import take_snapshot


class TestLeetcodePuzzle(TestCase):
    """This testcase will use a live LeetCode puzzle to ensure current functionality.

    Since websites are ever in flux, it makes sense to always assert that
    this class will work on a live version of the website.

    This will use the 'two-sum' puzzle found here: https://leetcode.com/problems/two-sum/
    """

    # For use in mock calls
    valid_suffix = 'valid-puzzle-url-suffix'

    # The real deal!
    puzzle_suffix = 'two-sum'
    #puzzle_url_suffix = 'add-two-numbers'

    @classmethod
    def setUpClass(cls):
        """take_snapshot() is very slow, as it renders javascript using a
        headless browser. Collect test snapshot only when needed.
        """
        super().setUpClass()

        cls.maxDiff = 1500

        cls.assert_puzzle_cached('two-sum')
        cls.assert_puzzle_cached('add-two-numbers')

    @classmethod
    def assert_puzzle_cached(cls, puzzle_url_suffix):
        dir_script = Path(__file__).parent
        dir_snapshots = dir_script / 'snapshots'
        dir_snapshots.mkdir(exist_ok=True)
        path_snapshot = dir_snapshots / f'{puzzle_url_suffix}.html'

        if not path_snapshot.exists():
            print(f'Taking HTML snapshot of puzzle "{puzzle_url_suffix}" and storing in {dir_snapshots}...')
            take_snapshot(puzzle_url_suffix, dir_snapshots)

        html_text = path_snapshot.read_text()
        html = requests_html.HTML(html=html_text)

        puzzle_attr = cls.suffix_as_attr(puzzle_url_suffix)
        setattr(cls, puzzle_attr, html)

    @staticmethod
    def suffix_as_attr(puzzle_url_suffix):
        return puzzle_url_suffix.replace('-', '_')

    @classmethod
    def tearDownClass(cls):
        pass

    @classmethod
    def FakeDownloader(cls, puzzle_url_suffix):
        def _get(_url):
            return getattr(cls, cls.suffix_as_attr(puzzle_url_suffix))
        return _get

    def setUp(self):
        self.lcp = LeetCodePuzzle(self.valid_suffix, downloader=self.FakeDownloader('two-sum'))

    def tearDown(self):
        pass

    def test_instance(self):
        self.assertIsNotNone(self.lcp)

    def test_get_puzzle_html(self):
        self.assertEqual(None, self.lcp.html)
        self.lcp.get_puzzle_html()
        self.assertEqual(self.two_sum, self.lcp.html)

    def test_extract_puzzle_title(self):
        self.lcp.get_puzzle_html()
        self.lcp.extract_puzzle_title()
        self.assertEqual('1. Two Sum', self.lcp.title)

    def test_insert_placeholder_newlines(self):
        lines = [
            'These are\n',
            'some\nlines',
            'of text',
            '\nfor testing.',
        ]
        expected = [
            'These are',
            '',
            'some',
            'lines',
            'of text',
            '',
            'for testing.'
        ]
        actual = self.lcp.insert_placeholder_newlines(lines)
        self.assertListEqual(expected, actual)

    def test_remove_duplicate_whitespace_lines(self):
        lines = [
            'These are',
            ' ',
            '',
            '\xa0',
            'some',
            '',
            'lines',
            ' ',
            'of text',
            u'\xa0',
            'for testing.'
        ]
        expected = [
            'These are',
            '',
            'some',
            '',
            'lines',
            '',
            'of text',
            '',
            'for testing.'
        ]
        actual = self.lcp.remove_duplicate_whitespace_lines(lines)
        self.assertListEqual(expected, actual)

    def test_remove_border_whitespace_lines(self):
        lines = [
            '',
            'This is a line surrounded by whitespace.',
            '',
            'And here\'s another.',
            '',
        ]
        expected = [
            'This is a line surrounded by whitespace.',
            '',
            'And here\'s another.',
        ]
        actual = self.lcp.remove_border_whitespace_lines(lines)
        self.assertListEqual(expected, actual)

    def test_extract_puzzle_summary(self):
        expected = [
            'Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.',
            '',
            'You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.',
            '',
            'You can return the answer in any order.',
            '',
            '**Example 1:**',
            '```',
            'Input: nums = [2,7,11,15], target = 9',
            'Output: [0,1]',
            'Output: Because nums[0] + nums[1] == 9, we return [0, 1].',
            '```',
            '',
            '**Example 2:**',
            '```',
            'Input: nums = [3,2,4], target = 6',
            'Output: [1,2]',
            '```',
            '',
            '**Example 3:**',
            '```',
            'Input: nums = [3,3], target = 6',
            'Output: [0,1]',
            '```',
            '',
            '**Constraints:**',
            '- `2 <= nums.length <= 103`',
            '- `-109 <= nums[i] <= 109`',
            '- `-109 <= target <= 109`',
            '- *Only one valid answer exists.*'
        ]
        self.lcp.get_puzzle_html()
        self.lcp.extract_puzzle_summary()

        for e, a in zip(expected, self.lcp.summary):
            print(repr(e))
            print(repr(a))
            print('---\n')

        self.assertListEqual(expected, self.lcp.summary)

    def test_extract_given_code(self):
        expected = [
            'class Solution {',
            'public:',
            'vector<int> twoSum(vector<int>& nums, int target) {',
            '',
            '}',
            '};'
        ]
        self.lcp.get_puzzle_html()
        self.lcp.extract_given_code()
        self.assertListEqual(expected, self.lcp.code)


if __name__ == '__main__':
    main()
