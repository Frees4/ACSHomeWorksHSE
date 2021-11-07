from abc import ABC, abstractmethod
from enum import IntEnum
from functools import cached_property
from typing import TextIO


class Text(ABC):
    class Key(IntEnum):
        CHAR_CHAR_ENCRYPTION = 1
        SHIFT_ENCRYPTION = 2
        CHAR_INT_ENCRYPTION = 3

    def __init__(self, text: str) -> None:
        self.text = text

    @classmethod
    @abstractmethod
    def from_file(cls, text: str, input_file: TextIO):
        pass

    @classmethod
    @abstractmethod
    def random_encryption(cls, text: str):
        pass

    def __len__(self):
        return len(self.text)

    @cached_property
    def hash(self) -> float:
        return 0.0 if len(self) == 0 else sum(map(ord, self.text)) / len(self)

    @abstractmethod
    def encrypted_text(self) -> str:
        pass

    def output(self, output_file: TextIO) -> None:
        hash_string = '{:.4f}'.format(self.hash).rstrip("0").rstrip(".")
        print(f'"{self.text}", Hash={hash_string};', end=' ', file=output_file)
