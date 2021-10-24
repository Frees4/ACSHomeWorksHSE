#include <cstdio>
#include "shift_encryption.h"
#include "error.h"
#include "text.h"

ShiftEncryption::~ShiftEncryption() {
    delete[] encrypted_text_;
}

void ShiftEncryption::Input(FILE *file) {
    if (fscanf(file, "%u ", &shift_) == 0) {
        Error("Incorrect shift");
    }
}

void ShiftEncryption::RandomEncryption(size_t min_param, size_t max_param) {
    shift_ = rand() % (max_param - min_param + 1) + min_param;
}

void ShiftEncryption::Output(FILE *file) const {
    Text::Output(file);
    fprintf(file, "Shift: %d; Result: \"%s\"\n", shift_, encrypted_text_);
}

void ShiftEncryption::Encrypt() {
    encrypted_text_ = new unsigned char[length_ + 1];
    int shift = shift_ % 8;
    for (size_t index = 0; index < length_; ++index) {
        unsigned char symbol = string_[index];
        symbol = (symbol << shift) | (symbol >> (8 - shift));
        encrypted_text_[index] = (char)symbol;
    }
    encrypted_text_[length_] = '\0';
}
