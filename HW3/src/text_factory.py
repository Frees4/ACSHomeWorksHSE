import random
from typing import TextIO

from src.char_encryption import CharEncryption
from src.shift_encryption import ShiftEncryption
from src.text import Text
from src.utils import read_non_space_symbol, read_symbol, VALID_SYMBOLS


def input_text(input_file: TextIO) -> Text:
    try:
        key = int(read_non_space_symbol(input_file))
        if key < 1 or key > 3 or \
                read_non_space_symbol(input_file) != '"':
            raise
    except Exception:
        raise ValueError("Invalid cypher type")
    raw_content = []
    while True:
        current_symbol = read_symbol(input_file)
        if current_symbol == '\\':
            current_symbol = read_symbol(input_file)
        elif current_symbol == '"':
            break
        raw_content.append(current_symbol)
    content = ''.join(raw_content)
    text: Text
    if key == Text.Key.CHAR_CHAR_ENCRYPTION:
        text = CharEncryption.from_file(content, input_file)
    elif key == Text.Key.CHAR_INT_ENCRYPTION:
        text = CharEncryption.from_file__to_int(content, input_file, True)
    else:
        text = ShiftEncryption.from_file(content, input_file)
    return text


def random_text() -> Text:
    content = ''.join([random.choice(VALID_SYMBOLS) for _ in
                      range(random.randint(0, 20))])
    key = random.randint(1, 3)
    text: Text
    if key == Text.Key.CHAR_CHAR_ENCRYPTION:
        text = CharEncryption.random_encryption(content)
    elif key == Text.Key.CHAR_INT_ENCRYPTION:
        text = CharEncryption.random_encryption__to_int(content, True)
    else:
        text = ShiftEncryption.random_encryption(content)
    return text
