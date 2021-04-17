import argparse
import os
import sys
from pathlib import Path

from html_downloader import HTMLDownloader


def parse_args():
    parser = argparse.ArgumentParser(description='Store an HTML snapshot of the given LeetCode puzzle.')
    parser.add_argument('--puzzle', help='URL suffix of the puzzle to retreive, e.g. "two-sum".', required=True)
    parser.add_argument('--dir', help='Directory to save the snapshot in.', required=True)

    return parser.parse_args()


def take_snapshot(puzzle_suffix, directory):
    path = Path(directory)
    path.mkdir(exist_ok=True)
    path /= f'{puzzle_suffix}.html'

    puzzle = HTMLDownloader.get('https://leetcode.com/problems/' + puzzle_suffix)

    path.write_bytes(puzzle.raw_html)


if __name__ == '__main__':
    cli = parse_args()
    try:
        print('Taking snapshot...')
        take_snapshot(cli.puzzle, cli.dir)
    except:
        print('Failed to take snapshot.')
        raise
    else:
        print(f'Saved snapshot to {cli.dir}/{cli.puzzle}.html')
