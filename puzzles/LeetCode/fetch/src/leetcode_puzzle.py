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

        summary = self.md.convert(selection).split('\n')
        summary = self.reformat_puzzle_summary(summary)
        summary = self.insert_placeholder_newlines(summary)
        summary = self.remove_duplicate_whitespace_lines(summary)
        summary = self.remove_border_whitespace_lines(summary)

        self.summary = summary

    def reformat_puzzle_summary(self, summary):
        formatted_summary = []

        for i, line in enumerate(summary):
            line_prev = self._get_prev_line(i, summary)
            line_next = self._get_next_line(i, summary)

            insertion = self._accept_line(line_prev, line, line_next)

            if insertion is not None:
                formatted_summary.append(insertion)

        return formatted_summary

    def _get_prev_line(self, index, lines):
        if index == 0:
            # Do not return the final element (0-1 = -1) in the list.
            value = None
        else:
            value = lines[index - 1]

        return value

    def _get_next_line(self, index, lines):
        try:
            value = lines[index + 1]
        except IndexError:
            value = None

        return value

    def _accept_line(self, line_prev, line, line_next):
        example = re.compile(r'[Ee]xample \d+')

        if line_prev == '```' and line == '':
            line = None

        elif line == '' and line_next == '```':
            line = None

        elif line_prev != '' and example.search(line):
            line = '\n' + line

        elif example.search(line_prev or '') and line == '':
            line = None

        return line

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
