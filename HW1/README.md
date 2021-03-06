# Статически типизированная архитектура ВС, ориентированная на процедурный подход
*Вариант 303, условие задачи 9, дополнительная функция 22*  
[Описание задания](#%D0%BE%D0%BF%D0%B8%D1%81%D0%B0%D0%BD%D0%B8%D0%B5-%D0%B7%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F)  
[Описание реализации](#%D0%BE%D0%BF%D0%B8%D1%81%D0%B0%D0%BD%D0%B8%D0%B5-%D1%80%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8)  
[Формат ввода и вывода](#%D1%84%D0%BE%D1%80%D0%BC%D0%B0%D1%82-%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0-%D0%B8-%D0%B2%D1%8B%D0%B2%D0%BE%D0%B4%D0%B0)  
[Характеристики программы](#%D1%85%D0%B0%D1%80%D0%B0%D0%BA%D1%82%D0%B5%D1%80%D0%B8%D1%81%D1%82%D0%B8%D0%BA%D0%B8-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D1%8B)  
[Структура вычислительной системы](#%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D0%B0-%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D0%B9-%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D1%8B)
## Описание задания
Обобщенный артефакт, используемый в задании|Базовые альтернативы (уникальные параметры, задающие отличительные признаки альтернатив)|Общие для всех альтернатив переменные|Общие для всех альтернатив функции|Дополнительная функция
-------------------------------------------|----------------------------------------------------------------------------------------|-------------------------------------|----------------------------------|----------------------
Тексты, состоящие из цифр и латинских букв, зашифрованные различными способами.|1. Шифрование заменой символов (указатель на массив из T пар: [текущий символ, замещающий символ]; зашифрованный текст – строка символов) 2. Шифрование циклическим сдвигом *влево* кода каждого символа на T (целое число, определяющее сдвиг; зашифрованный текст – строка символов) 3. Шифрование заменой символов на числа (T пар: текущий символ, целое число – подстановка при шифровании кода символа в виде короткого целого; зашифрованный текст – целочисленный массив). *По умолчанию символ заменяется на его ASCII-код*|Открытый текст - строка символов.|`Hash`: частное от деления суммы кодов незашифрованной строки на число символов в этой строке (действительное число), *либо 0 для пустой строки*.|Переместить в конец контейнера те элементы, для которых значение, полученное с использованием функций, общей для всех альтернатив, больше чем среднее арифметическое для всех элементов контейнера, полученное с использованием этой же функции. Остальные элементы сдвинуть к началу без изменения их порядка.
## Описание реализации
Программа написана на C++ в стиле языка C. Использована система сборки CMake. Также имеется скрипт test.py (Python 3) для автоматического тестирования и измерения времени работы для каждого теста. Вызов программы из cmake-build-debug: `./task <input-file> <output-file>`. Исходные коды программы расположены в папке 'src', входные и выходные данные тестов в папках 'input' и 'output' соответственно. Программа реагирует на ошибки ввода, выводя в выходной файл соответствующее сообщение.
## Формат ввода и вывода
В первой строке заданы 2 числа N и M - размер контейнера и способ ввода (0 для ввода готовых данных либо зерно функции `srand` для генерации случайных данных). Далее, если M != 0, на второй строке через пробел задаются тип генерируемых элементов (0 для произвольного типа либо номер конкретного типа из таблицы выше), минимальная и максимальная длина текста, а также минимальное и максимальное значение параметра шифра T. Иначе следующие N строк описывают готовые данные: в каждой строке через пробел заданы тип шифра, текст в двойных кавычках (`"` и `\` внутри текста записываются как `\"` и `\\`), параметр T, а также при необходимости перечисление через пробел пар вида `символ-символ` или `символ-число` (лишние пробелы между парами недопустимы, так как символ в паре сам может быть пробелом).
Пример ввода:
```
3 0
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
```
## Характеристики программы
⠀|⠀
-|-
Число интерфейсных модулей|5
Число модулей реализации|5
Общий размер исходных текстов|15 108 байт
Размер исполняемого файла|23 400 байт

Номер теста|Время работы теста (сек.)
-|-
1-12|≈0
rand1 *(20 элементов)*|≈0
rand2 *(1000 элементов)*|0.012055
rand3 *(10000 элементов)*|0.016463
## Структура вычислительной системы
![Структура ВС](https://user-images.githubusercontent.com/70819094/136711230-796366e0-fe5f-4c93-a5fc-1290874d77f3.png)

