#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include "text.h"
#include "char_encryption.h"
#include "shift_encryption.h"
#include "error.h"

double Hash(const Text& text) {
    if (text.length == 0) {
        return 0.0;
    }
    int64_t sum = 0;
    for (size_t index = 0; index < text.length; ++index) {
        sum += text.string[index];
    }
    return (double)sum / text.length;
}

unsigned char ReadSymbol(FILE* file) {
    int i = fgetc(file);
    if (i == EOF) {
        Error("Unexpected end of file");
    }
    return i;
}

void InputText(FILE *file, Text **out) {
    int key;
    if (fscanf(file, "%u \"", &key) == 0 || key == 0 || key > 3) {
        Error("Invalid cypher type");
    }
    Text* text;
    switch (key) {
        case Text::Key::kCharCharEncryption:
        case Text::Key::kCharIntEncryption:
            text = (Text*)new CharEncryption;
            break;
        default:
            text = (Text*)new ShiftEncryption;
    }
    *out = text;
    text->key = (Text::Key)key;
    size_t length = 0;
    size_t capacity = 1;
    auto* string = new unsigned char[capacity];
    unsigned char current;
    while ((current = ReadSymbol(file)) != '"') {
        current = current == '\\' ? ReadSymbol(file) : current;
        if (length + 1 == capacity) {
            capacity = capacity == 0 ? 1 : capacity * 2;
            auto* new_array = new unsigned char[capacity];
            memcpy(new_array, string, length);
            delete[] string;
            string = new_array;
        }
        string[length++] = current;
    }
    string[length] = '\0';
    text->string = string;
    text->length = length;
    int _ = fscanf(file, " "); ++_;
    if (key == Text::Key::kShiftEncryption) {
        InputShiftEncryption(file, (ShiftEncryption*)text);
    } else {
        InputCharEncryption(file, (CharEncryption*)text);
    }
}

Text* RandomText(int cypher, size_t min_length, size_t max_length,
                 size_t min_param, size_t max_param) {
    int key = cypher == 0 ? rand() % 3 + 1 : cypher;
    Text* text;
    switch (key) {
        case Text::Key::kCharCharEncryption:
        case Text::Key::kCharIntEncryption:
            text = (Text*)new CharEncryption;
            break;
        default:
            text = (Text*)new ShiftEncryption;
    }
    text->key = (Text::Key)key;
    size_t length = rand() % (max_length - min_length + 1) + min_length;
    text->length = length;
    text->string = new unsigned char[length + 1];
    for (size_t index = 0; index < length; ++index) {
        text->string[index] = RandomSymbol();
    }
    text->string[length] = '\0';
    if (key == Text::Key::kShiftEncryption) {
        RandomShiftEncryption((ShiftEncryption*)text, min_param, max_param);
    } else {
        RandomCharEncryption((CharEncryption*)text, min_param, max_param);
    }
    return text;
}

void OutputText(FILE *file, const Text &text) {
    fprintf(file, "\"%s\", Hash=%g; ", text.string, Hash(text));
    if (text.key == Text::kShiftEncryption) {
        OutputShiftEncryption(file, (const ShiftEncryption&)text);
    } else {
        OutputCharEncryption(file, (const CharEncryption&)text);
    }
}

void DeleteText(Text *text) {
    if (text == nullptr) {
        return;
    }
    delete[] text->string;
    if (text->key == Text::kShiftEncryption) {
        auto* value = (ShiftEncryption*)text;
        DeleteShiftEncryption(value);
    } else {
        auto* value = (CharEncryption*)text;
        DeleteCharEncryption(value);
    }
}

bool ValidSymbol(unsigned char symbol) {
    return symbol == ' ' || (symbol >= '0' && symbol <= '9') || (symbol >= 'a' && symbol <= 'z')
        || (symbol >= 'A' && symbol <= 'Z');
}

unsigned char RandomSymbol() {
    unsigned char next;
    do {
        next = rand() % 256;
    } while (!ValidSymbol(next));
    return next;
}
