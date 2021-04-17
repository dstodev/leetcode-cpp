from unittest import TestCase, main, mock

import html_downloader
from html_downloader import HTMLDownloader


class TestHTMLDownloader(TestCase):
    def test_get(self):
        with mock.patch('html_downloader.SESSION') as session:
            html = HTMLDownloader.get('valid-url')

            self.assertTrue(session.get.called)
            self.assertTrue(html.render.called)


if __name__ == '__main__':
    main()
