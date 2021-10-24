#include <cstdint>
#include <cstring>
#include <cstdio>
#include "text.h"
#include "error.h"
#include "char_encryption.h"
#include "shift_encryption.h"

Text::~Text() {
    delete[] string_;
}

double Text::Hash() const {
    if (length_ == 0) {
        return 0.0;
    }
    int64_t sum = 0;
    for (size_t index = 0; index < length_; ++index) {
        sum += string_[index];
    }
    return (double)sum / length_;
}

unsigned char ReadSymbol(FILE* file) {
    int i = fgetc(file);
    if (i == EOF) {
        Error("Unexpected end of file");
    }
    return i;
}

Text* Text::InputText(FILE *file) {
    int key;
    if (fscanf(file, "%u \"", &key) == 0 || key == 0 || key > 3) {
        Error("Invalid cypher type");
    }
    Text* text;
    switch (key) {
        case Text::Key::kCharCharEncryption:
            text = (Text*)new CharEncryption(false);
            break;
        case Text::Key::kCharIntEncryption:
            text = (Text*)new CharEncryption(true);
            break;
        default:
            text = (Text*)new ShiftEncryption;
    }
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
    text->string_ = string;
    text->length_ = length;
    int _ = fscanf(file, " "); ++_;
    text->Input(file);
    text->Encrypt();
    return text;
}

bool ValidSymbol(unsigned char symbol) {
    return symbol == ' ' || (symbol >= '0' && symbol <= '9') || (symbol >= 'a' && symbol <= 'z')
        || (symbol >= 'A' && symbol <= 'Z');
}

Text *Text::RandomText(int cypher, size_t min_length, size_t max_length,
                       size_t min_param, size_t max_param) {
    int key = cypher == 0 ? rand() % 3 + 1 : cypher;
    Text* text;
    switch (key) {
        case Text::Key::kCharCharEncryption:
            text = (Text*)new CharEncryption(false);
            break;
        case Text::Key::kCharIntEncryption:
            text = (Text*)new CharEncryption(true);
            break;
        default:
            text = (Text*)new ShiftEncryption;
    }
    size_t length = rand() % (max_length - min_length + 1) + min_length;
    text->length_ = length;
    text->string_ = new unsigned char[length + 1];
    for (size_t index = 0; index < length; ++index) {
        text->string_[index] = RandomSymbol();
    }
    text->string_[length] = '\0';
    text->RandomEncryption(min_param, max_param);
    text->Encrypt();
    return text;
}

void Text::Output(FILE *file) const {
    fprintf(file, "\"%s\", Hash=%g; ", string_, Hash());
}

unsigned char Text::RandomSymbol() {
    unsigned char next;
    do {
        next = rand() % 256;
    } while (!ValidSymbol(next));
    return next;
}
