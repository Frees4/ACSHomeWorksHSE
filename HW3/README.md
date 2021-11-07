# Архитектура ВС с динамической типизацией
*Вариант 303, условие задачи 9, дополнительная функция 22*  
[Описание задания](#%D0%BE%D0%BF%D0%B8%D1%81%D0%B0%D0%BD%D0%B8%D0%B5-%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F)  
[Описание реализации](#%D0%BE%D0%BF%D0%B8%D1%81%D0%B0%D0%BD%D0%B8%D0%B5-%D1%80%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8)  
[Формат ввода и вывода](#%D1%84%D0%BE%D1%80%D0%BC%D0%B0%D1%82-%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0-%D0%B8-%D0%B2%D1%8B%D0%B2%D0%BE%D0%B4%D0%B0)  
[Характеристики программы](#%D1%85%D0%B0%D1%80%D0%B0%D0%BA%D1%82%D0%B5%D1%80%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B8-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D1%8B)  
[Структура вычислительной системы](#%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0-%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D0%B9-%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D1%8B)
## Описание задания
Обобщенный артефакт, используемый в задании|Базовые альтернативы (уникальные параметры, задающие отличительные признаки альтернатив)|Общие для всех альтернатив переменные|Общие для всех альтернатив функции|Дополнительная функция
-------------------------------------------|----------------------------------------------------------------------------------------|-------------------------------------|----------------------------------|----------------------
Тексты *в кодировке ASCII*, состоящие из цифр и латинских букв, зашифрованные различными способами.|1. Шифрование заменой символов (указатель на массив из T пар: [текущий символ, замещающий символ]; зашифрованный текст – строка символов) 2. Шифрование циклическим сдвигом *влево* кода каждого символа на T *в пределах 7 бит* (целое число, определяющее сдвиг; зашифрованный текст – строка символов) 3. Шифрование заменой символов на числа (T пар: текущий символ, целое число – подстановка при шифровании кода символа в виде короткого целого; зашифрованный текст – целочисленный массив). *По умолчанию символ заменяется на его ASCII-код*|Открытый текст - строка символов.|`Hash`: частное от деления суммы кодов незашифрованной строки на число символов в этой строке (действительное число), *либо 0 для пустой строки*.|Переместить в конец контейнера те элементы, для которых значение, полученное с использованием функций, общей для всех альтернатив, больше чем среднее арифметическое для всех элементов контейнера, полученное с использованием этой же функции. Остальные элементы сдвинуть к началу без изменения их порядка..
## Описание реализации
Программа написана на Python 3 в объектно-ориентированном стиле и является кроссплатформенной. Точка входа - main.py в главной папке. Имеется скрипт test.py для автоматического тестирования и вывода времени работы, измеренного программой, для каждого теста. Запуск программы: `python main.py -f <входной-файл> <выходной-файл>` для ввода данных из файла, либо `python main.py -n <размер-контейнера> <выходной-файл>` для случайной генерации контейнера заданного размера. Исходные коды программы (кроме main.py и test.py) расположены в папке 'src', входные и выходные данные тестов в папках 'input' и 'output' соответственно. Программа реагирует на ошибки ввода, выводя в выходной файл соответствующее сообщение.
## Формат ввода и вывода
В первой строке задано число N - размер контейнера. Следующие N строк описывают элементы контейнера: в каждой строке через пробел заданы тип шифра, текст в двойных кавычках (`"` и `\` внутри текста записываются как `\"` и `\\`), параметр T, а также при необходимости перечисление через пробел пар вида `символ-символ` или `символ-число` (лишние пробелы между парами недопустимы, так как символ в паре сам может быть пробелом).
Пример ввода:
```
3
1 "\"Hello world!\"" 3 "-' H-h l-L
2 "" 2
3 "123" 3 1-50 2-100 3-150
```
Пример вывода:
```
Container has 3 elements
1. ""Hello world!"", Hash=84.6429; Replacements: 3 ("-' H-h l-L); Result: "'heLLo worLd!'"
2. "", Hash=0; Shift: 2; Result: ""
3. "123", Hash=50; Replacements: 3 (1-50 2-100 3-150); Result: [50 100 150]


Mean: 44.880952
Move Result: 
"", Hash=0; Shift: 2; Result: ""
""Hello world!"", Hash=84.6429; Replacements: 3 ("-' H-h l-L); Result: "'heLLo worLd!'"
"123", Hash=50; Replacements: 3 (1-50 2-100 3-150); Result: [50 100 150]
3. "", Hash=0; Shift: 2; Result: ""
```
## Характеристики программы
⠀                            |HW1                    |HW2                  |HW3
-----------------------------|-----------------------|-------------|----------------------
Число интерфейсных модулей   |5                      |5            |-
Число модулей реализации     |5                      |5            |8
Общий размер исходных текстов|15 108 байт            |12 980 байт  |13 326 байт
Размер исполняемого файла    |23 400 байт            |29 208 байт  |15 273 байт (\__pycache\__)
**Тест**                     |**Время работы теста (сек.)**        
1-10                         |≈0                     |≈0           |0.00043 - 0.00234
rand1 *(20 элементов)*       |≈0                     |≈0           |0.00261
rand2 *(1000 элементов)*     |0.012055               |0.012055     |0.012015
rand3 *(10000 элементов)*    |0.016463               |0.016463     |1.11007

По сравнению с предыдущей работой увеличилось число модулей реализации (из-за запрета циклических зависимостей требуется бóльшая модульность), несколько уменьшился размер исходных текстов, исчез исполняемый файл (вместо него интерпретатор генерирует во время исполнения более компактный байт-код), и в разы упала производительность. С одной стороны, Python в какой-то степени упрощает программирование и обеспечивает компактность и кроссплатформенность программ. С другой стороны, Python как интерпретируемый язык с динамической типизацией сильно проигрывает в производительности компилируемым языкам со статической типизацией.
## Структура вычислительной системы
### Таблица типов
Тип     |Размер в байтах         
--------|---------------
type    |880 + 40n
object  |16
None    |-
bool    |32 + 4n
int     |24 + 4n
float   |24
list    |40
tuple   |24 + 8n
range   |48
str     |80
set     |200
dict    |48
BaseException|64
TextIO  |16
ABC     |16
IntEnum |32 + 4n
*Классы в программе*|32
### Таблица классов
Классы   |Имена     |Описания
---------|----------|-------------
Container|\__init\__|`def __init__(self, array: List[Text]) -> None`
| |from_file|`def from_file(cls, input_file: TextIO)`
| |from_random_elements|`def from_random_elements(cls, length: int)`
| |\__len\__|`def __len__(self) -> int`
| |move_function|`def move_function(self, output_file: TextIO) -> None`
| |output|`def output(self, output_file: TextIO) -> None`
Text     |Key       |`class Key(IntEnum)`
| |\__init\__|`def __init__(self, text: str) -> None`
| |from_file|`def from_file(cls, text: str, input_file: TextIO)`
| |random_encryption|`def random_encryption(cls, text: str)`
| |\__len\__|`def __len__(self)`
| |hash|`def hash(self) -> float`
| |encrypted_text|`def encrypted_text(self) -> str`
| |output|`def output(self, output_file: TextIO) -> None`
CharEncryption|\__init\__|`def __init__(self, text: str, replacements: List[Tuple[str, Union[int, str]]], to_int: bool) -> None`
| |from_file|`def from_file(cls, text: str, input_file: TextIO) -> Text`
| |from_file__to_int|`def from_file__to_int(cls, text: str, input_file: TextIO, to_int: bool) -> Text`
| |random_encryption|`def random_encryption(cls, text: str) -> Text`
| |random_encryption__to_int|`def random_encryption__to_int(cls, text: str, to_int: bool) -> Text`
| |replacement_string|`def replacement_string(self, index: int) -> str`
| |output|`def output(self, output_file: TextIO) -> None`
| |encrypted_text|`def encrypted_text(self) -> str`
| |valid_replacements|`def valid_replacements(self) -> bool`
ShiftEncryption|\__init\__|`def __init__(self, text: str, shift: int)`
| |from_file|`def from_file(cls, text: str, input_file: TextIO) -> Text`
| |random_encryption|`def random_encryption(cls, text: str) -> Text`
| |output|`def output(self, output_file: TextIO) -> None`
| |encrypted_text|`def encrypted_text(self) -> str`
### Память программы
Методы       |Имена     |Объекты
-------------|----------|----------------
*main.py*    |\__name\__|str `"__main__"`
src.main.main|args      |Tuple[str] `("-f", "input/10.in", "10.out")`
| |file_input|bool `True`
| |input_file|TextIO
| |random_elements_count|int
| |output_file|TextIO
| |start|float
| |container|Container
| |exception|Exception
src.container.Container.\__init\__|array|List[Text]
src.container.Container.from_file|input_file|TextIO
| |length|int
src.container.Container.from_random_elements|length|int
src.container.Container.move_function|output_file|TextIO
| |sum|float
| |mean|float
| |elem|Text
src.container.Container.output|output_file|TextIO
| |index|int
src.text.Text.\__init\__|text|str
src.text.Text.output|output_file|TextIO
| |hash_string|str
src.text_factory.input_text|input_file|TextIO
| |key|int
| |raw_content|List[str]
| |current_symbol|str
| |content|str
| |text|Text
src.text_factory.random_text|content|str
| |key|int
| |text|Text
src.utils.read_symbol|input_file|TextIO
| |next_symbol|str
src.utils.read_non_space_symbol|input_file|TextIO
| |next_symbol|str
src.utils.read_until_space|input_file|TextIO
| |token|List[str]
| |next_symbol|str
src.char_encryption.CharEncryption.\__init\__|text|str
| |replacements|List[Tuple[str, Union[int, str]]]
| |to_int|bool
src.char_encryption.CharEncryption.from_file|text|str
| |input_file|TextIO
src.char_encryption.CharEncryption.from_file__to_int|text|str
| |input_file|TextIO
| |to_int|bool
| |replacement_count|int
| |replacements|List[Tuple[str, Union[int, str]]]
| |from_symbol|str
| |to_symbol|Union[int, str]
| |space|str
| |text_object|CharEncryption
src.char_encryption.CharEncryption.random_encryption|text|str
src.char_encryption.CharEncryption.random_encryption__to_int|text|str
| |to_int|bool
| |count|int
| |set_1|set
| |set_2|Union[List[bool], set]
| |replacements|List[Tuple[str, Union[int, str]]]
| |from_symbol|str
| |to_symbol|Union[int, str]
src.char_encryption.CharEncryption.replacement_string|index|int
src.char_encryption.CharEncryption.output|output_file|TextIO
| |index|int
src.char_encryption.CharEncryption.encrypted_text|replacement_map|Dict[str, Union[int, str]]
| |pair|Tuple[str, Union[int, str]]
| |encrypted|List[Union[int, str]]
| |symbol|str
src.char_encryption.CharEncryption.valid_replacements|pair|Tuple[str, Union[int, str]]
src.shift_encryption.ShiftEncryption.\__init\__|text|str
| |shift|int
src.shift_encryption.ShiftEncryption.from_file|text|str
| |input_file|TextIO
| |shift|int
src.shift_encryption.ShiftEncryption.random_encryption|text|str
src.shift_encryption.ShiftEncryption.output|output_file|TextIO
src.shift_encryption.ShiftEncryption.encrypted_text|left_shift|int
| |right_shift|int
| |symbol|str
