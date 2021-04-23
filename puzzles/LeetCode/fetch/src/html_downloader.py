# https://github.com/psf/requests
# https://github.com/psf/requests-html
from requests_html import HTMLSession

SESSION = HTMLSession()

# http_headers = {
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.66 Safari/537.36',
#     'Upgrade-Insecure-Requests': '1',
#     'Cache-Control': 'no-cache',
#     'DNT': '1',
#     'Sec-Fetch-Site': 'none',
#     'Sec-Fetch-Mode': 'navigate',
#     'Sec-Fetch-User': 'document'
# }


class HTMLDownloader:

    @staticmethod
    def get(url):
        r = SESSION.get(url)
        r.html.render()
        return r.html
