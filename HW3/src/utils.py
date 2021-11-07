import string
from typing import TextIO

VALID_SYMBOLS = " " + string.digits + string.ascii_letters


def read_symbol(input_file: TextIO) -> str:
    next_symbol = input_file.read(1)
    if next_symbol == '':
        raise EOFError("Unexpected end of file")
    return next_symbol


def read_non_space_symbol(input_file: TextIO) -> str:
    while True:
        next_symbol = read_symbol(input_file)
        if not next_symbol.isspace():
            return next_symbol


def read_until_space(input_file: TextIO) -> str:
    token = [read_non_space_symbol(input_file)]
    while True:
        next_symbol = input_file.read(1)
        if next_symbol.isspace() or next_symbol == '':
            return ''.join(token)
        token.append(next_symbol)
