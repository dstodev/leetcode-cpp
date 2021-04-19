import re

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
        selection = self.html.find(selector)
        selection = [s.html for s in selection]

        summary = self.html_to_md(selection)
        summary = self.reformat_puzzle_summary(summary)
        summary = self.insert_placeholder_newlines(summary)
        summary = self.remove_duplicate_whitespace_lines(summary)

        self.summary = summary

    def html_to_md(self, html):
        if isinstance(html, str):
            html = [html]
            return_as_str = True
        else:
            return_as_str = False

        md = []

        for line in html:
            line = re.sub(r'</?code>', '`', line)
            line = re.sub(r'</?strong>', '**', line)
            line = re.sub(r'</?em>', '*', line)
            line = re.sub(r'</?pre>', '```', line)
            line = re.sub(r'<p>', '', line)
            line = re.sub(r'</p>', '\n', line)
            line = re.sub(r'\xa0', ' ', line)
            md.append(line)

        if return_as_str:
            md = md[0]

        return md

    def reformat_puzzle_summary(self, summary):
        return summary

    def insert_placeholder_newlines(self, lines):
        expanded_lines = []

        for line in lines:
            tokens = line.split('\n')
            expanded_lines.extend(tokens)

        return expanded_lines

    def remove_duplicate_whitespace_lines(self, lines):
        sanitized_lines = []
        whitespace_inserted = False

        for line in lines:
            if line.strip():
                sanitized_lines.append(line)
                whitespace_inserted = False
            else:
                if not whitespace_inserted:
                    sanitized_lines.append('')
                    whitespace_inserted = True

        return sanitized_lines

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
