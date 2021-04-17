from html_downloader import HTMLDownloader


class LeetCodePuzzle:
    def __init__(self, puzzle_suffix, downloader=HTMLDownloader.get):
        self.url = 'https://leetcode.com/problems/' + puzzle_suffix
        self.get = downloader
        self.html = None

        self.title = ''
        self.summary = []
        self.code = []

    def fetch(self):
        self.get_puzzle_html()
        self.extract_puzzle_title()
        self.extract_puzzle_summary()
        self.extract_given_code()

    def get_puzzle_html(self):
        self.html = self.get(self.url)

    def extract_puzzle_title(self):
        selector = 'div[data-cy=question-title]'  # https://www.w3schools.com/cssref/css_selectors.asp
        element = self.html.find(selector)[0]
        self.title = element.text

    def extract_puzzle_summary(self):
        selector = 'div[class*=question-content] > div > *'  # https://www.w3schools.com/css/css_combinators.asp
        summary = self.html.find(selector)
        for element in summary:
            line = self.html_to_md(element)
            self.summary.append(line)

    def html_to_md(self, element):
        pass

    def extract_given_code(self):
        selector = '.CodeMirror'
        element = self.html.find(selector)[0]
        code_raw = element.text
        code = []
        token_was_line_number = False

        for token in code_raw.split('\n')[1:]:
            try:
                int(token)
                # Token is a line number

                if (token_was_line_number):
                    # If the previous token was a line number, then it represented a blank line.
                    # Insert one now.
                    code.append('')

                token_was_line_number = True
            except ValueError:
                # Token is a line of code
                token_was_line_number = False
                code.append(token)

        self.code = code
