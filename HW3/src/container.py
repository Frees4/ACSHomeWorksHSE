from typing import List, TextIO

from src.text import Text
from src.text_factory import input_text, random_text


class Container:
    def __init__(self, array: List[Text]) -> None:
        self.array = array

    @classmethod
    def from_file(cls, input_file: TextIO):
        try:
            length = int(input_file.readline())
            if length < 0:
                raise
        except Exception:
            raise ValueError("Invalid container parameters")
        return cls([input_text(input_file) for _ in range(length)])

    @classmethod
    def from_random_elements(cls, length: int):
        return cls([random_text() for _ in range(length)])

    def __len__(self) -> int:
        return len(self.array)

    def move_function(self, output_file: TextIO):
        sum = 0.0
        for elem in self.array:
            sum += elem.hash
        if len(self) != 0:
            mean = sum / len(self)
        else:
            mean = 0
        print(f"Mean: {mean}", file=output_file)
        print("Move Result: ", file=output_file)
        for elem in self.array:
            if elem.hash <= mean:
                elem.output(output_file)
        for elem in self.array:
            if elem.hash > mean:
                elem.output(output_file)

    def output(self, output_file: TextIO) -> None:
        print("Container has", len(self), "elements", file=output_file)
        for index in range(len(self)):
            print(index + 1, end=". ", file=output_file)
            self.array[index].output(output_file)
