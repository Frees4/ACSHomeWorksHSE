import random
from functools import cached_property
from typing import TextIO, Tuple, List, Union

from src.text import Text
from src.utils import read_until_space, read_symbol, VALID_SYMBOLS


class CharEncryption(Text):
    MAX_REPLACEMENTS = 63

    def __init__(self, text: str,
                 replacements: List[Tuple[str, Union[int, str]]],
                 to_int: bool) -> None:
        super().__init__(text)
        self.replacements = replacements
        self.to_int = to_int

    @classmethod
    def from_file(cls, text: str, input_file: TextIO) -> Text:
        return cls.from_file__to_int(text, input_file, False)

    @classmethod
    def from_file__to_int(cls, text: str, input_file: TextIO,
                          to_int: bool) -> Text:
        try:
            replacement_count = int(read_until_space(input_file))
            if replacement_count < 0:
                raise
        except Exception:
            raise ValueError("Invalid container parameters")
        replacements = []
        try:
            for _ in range(replacement_count):
                from_symbol = read_symbol(input_file)
                read_symbol(input_file)
                to_symbol = read_until_space(
                    input_file) if to_int else read_symbol(input_file)
                if not to_int:
                    space = input_file.read(1)
                    if not space.isspace() and space != '':
                        raise
                else:
                    to_symbol = int(to_symbol)
                    if to_symbol < 0 or to_symbol > 255:
                        raise
                replacements.append((from_symbol, to_symbol))
        except Exception:
            raise ValueError("Incorrect cypher parameter")
        text_object = cls(text, replacements, to_int)
        if not text_object.valid_replacements():
            raise ValueError("Cypher is not bijective or has repetitions")
        return text_object

    @classmethod
    def random_encryption(cls, text: str) -> Text:
        return cls.random_encryption__to_int(text, False)

    @classmethod
    def random_encryption__to_int(cls, text: str, to_int: bool) -> Text:
        count = random.randint(0, 20)
        set_1 = set()
        set_2 = [False] * 256 if to_int else set()
        replacements = []
        for _ in range(count):
            while True:
                from_symbol = random.choice(VALID_SYMBOLS)
                if from_symbol not in set_1:
                    break
            set_1.add(from_symbol)
            while True:
                to_symbol = random.randint(0, 255) \
                    if to_int else random.choice(VALID_SYMBOLS)
                if to_int and not set_2[to_symbol] or \
                        not to_int and to_symbol not in set_2:
                    break
            if to_int:
                set_2[to_symbol] = True
            else:
                set_2.add(to_symbol)
            replacements.append((from_symbol, to_symbol))
        return cls(text, replacements, to_int)

    def replacement_string(self, index: int) -> str:
        return f"{self.replacements[index][0]}-{self.replacements[index][1]}"

    def output(self, output_file: TextIO) -> None:
        super().output(output_file)
        print("Replacements: ", len(self.replacements), " (",
              ' '.join(self.replacement_string(index) for index in
                       range(len(self.replacements))), "); Result:",
              sep='', end=' ', file=output_file)
        if not self.to_int:
            print('"', self.encrypted_text, '"', sep='', file=output_file)
        else:
            print("[", ' '.join(map(str, self.encrypted_text)), "]", sep='',
                  file=output_file)

    @cached_property
    def encrypted_text(self) -> str:
        replacement_map = {pair[0]: pair[1] for pair in self.replacements}
        encrypted = [
            replacement_map.get(symbol, ord(symbol) if self.to_int else symbol)
            for symbol in self.text]
        return encrypted if self.to_int else ''.join(encrypted)

    def valid_replacements(self) -> bool:
        return False if len(
            self.replacements) > CharEncryption.MAX_REPLACEMENTS or len(
            set(pair[0] for pair in self.replacements)) < len(
            self.replacements) or len(
            set(pair[1] for pair in self.replacements)) < len(
            self.replacements) else True
