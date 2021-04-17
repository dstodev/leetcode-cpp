from pathlib import Path
from unittest import TestCase, main, mock

import requests_html

from leetcode_puzzle import LeetCodePuzzle
from take_snapshot import take_snapshot


class TestLeetcodePuzzle(TestCase):
    """This testcase will use a live LeetCode puzzle to ensure current functionality.

    Since websites are ever in flux, it makes sense to always assert that
    this class will work on a live version of the website.

    This will use the 'two-sum' puzzle found here: https://leetcode.com/problems/two-sum/
    """

    # For use in mock calls
    valid_suffix = 'valid-puzzle-url-suffix'

    # The real deal!
    #puzzle_suffix = 'two-sum'
    puzzle_url_suffix = 'add-two-numbers'

    @classmethod
    def setUpClass(cls):
        """ take_snapshot() is very slow, as it renders javascript using a
        headless browser. Collect test snapshot only when needed.
        """
        super().setUpClass()

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

    def test_extract_puzzle_summary(self):
        self.lcp.get_puzzle_html()
        self.lcp.extract_puzzle_summary()

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
