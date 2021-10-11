#include <cstdlib>
#include "shift_encryption.h"
#include "error.h"

void ShiftEncrypt(ShiftEncryption *text) {
    text->encrypted_text = new char[text->base.length + 1];
    int shift = text->shift % 8;
    for (size_t index = 0; index < text->base.length; ++index) {
        unsigned char symbol = text->base.string[index];
        symbol = (symbol << shift) | (symbol >> (8 - shift));
        text->encrypted_text[index] = (char)symbol;
    }
    text->encrypted_text[text->base.length] = '\0';
}

void InputShiftEncryption(FILE *file, ShiftEncryption *text) {
    if (fscanf(file, "%u ", &text->shift) == 0) {
        Error("Incorrect shift");
    }
    ShiftEncrypt(text);
}

void RandomShiftEncryption(ShiftEncryption *text, size_t min_param, size_t max_param) {
    text->shift = rand() % (max_param - min_param + 1) + min_param;
    ShiftEncrypt(text);
}

void OutputShiftEncryption(FILE *file, const ShiftEncryption &text) {
    fprintf(file, "Shift: %d; Result: \"%s\"\n", text.shift, text.encrypted_text);
}

void DeleteShiftEncryption(ShiftEncryption *text) {
    delete[] text->encrypted_text;
    delete text;
}
