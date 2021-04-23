import re

from src.html_downloader import HTMLDownloader
from src.html_to_markdown import HtmlToMarkdown


class LeetCodePuzzle:
    def __init__(self, puzzle_suffix, downloader=HTMLDownloader.get):
        self.url = 'https://leetcode.com/problems/' + puzzle_suffix
        self.get = downloader
        self.html = None

        self.title = ''
        self.summary = []
        self.code = []

        self.md = HtmlToMarkdown()

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

        summary = self.md.convert(selection)
        summary = self.insert_placeholder_newlines(summary)
        summary = self.remove_duplicate_whitespace_lines(summary)
        summary = self.remove_border_whitespace_lines(summary)
        summary = self.reformat_puzzle_summary(summary)

        self.summary = summary

    def reformat_puzzle_summary(self, summary):
        # formatted_summary = []

        # for i, (a, b) in enumerate(zip(summary[0::2], summary[1::2])):
        #     print(f'{2*i}. {a}')
        #     print(f'{2*i+1}. {b}')
        #     print()
        #     if a == '' and b == '```':
        #         pass
        #     else:
        #         formatted_summary.append(a)

        return summary

    def insert_placeholder_newlines(self, lines):
        expanded_lines = []

        if isinstance(lines, str):
            lines = [lines]

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

    def remove_border_whitespace_lines(self, lines):
        sanitized_lines = []

        if lines[0]:
            sanitized_lines.append(lines[0])

        sanitized_lines.extend(lines[1:-1])

        if lines[-1]:
            sanitized_lines.append(lines[-1])

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
