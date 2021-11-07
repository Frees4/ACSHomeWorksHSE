import random
from functools import cached_property
from typing import TextIO

from src.text import Text
from src.utils import read_until_space


class ShiftEncryption(Text):
    CODE_POINT_SIZE = 7

    def __init__(self, text: str, shift: int):
        super().__init__(text)
        self.shift = shift

    @classmethod
    def from_file(cls, text: str, input_file: TextIO) -> Text:
        try:
            shift = int(read_until_space(input_file))
        except Exception:
            raise ValueError("Incorrect shift")
        return cls(text, shift)

    @classmethod
    def random_encryption(cls, text: str) -> Text:
        return cls(text, random.randint(0, 20))

    def output(self, output_file: TextIO) -> None:
        super(ShiftEncryption, self).output(output_file)
        print(f'Shift: {self.shift}; Result: "{self.encrypted_text}"',
              file=output_file)

    @cached_property
    def encrypted_text(self) -> str:
        left_shift = self.shift % self.CODE_POINT_SIZE
        right_shift = self.CODE_POINT_SIZE - self.shift % self.CODE_POINT_SIZE
        return ''.join(chr(((ord(symbol) << left_shift) | (
                    ord(symbol) >> right_shift)) & (
                                       (1 << self.CODE_POINT_SIZE) - 1)) for
                       symbol in self.text)
