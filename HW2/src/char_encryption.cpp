#include <cstring>
#include <cstdio>
#include "char_encryption.h"
#include "error.h"
#include "text.h"

CharEncryption::CharEncryption(bool to_int) {
    to_int_ = to_int;
}

CharEncryption::~CharEncryption() {
    delete[] replacements_;
    delete[] encrypted_text_;
}

void CharEncryption::Input(FILE *file) {
    long count;
    if (fscanf(file, "%zu", &count) == 0 || count < 0) {
        Error("Invalid container parameters");
    }
    replacement_count_ = count;
    replacements_ = new Replacement[count];
    for (long counter = 0; counter < count; ++counter) {
        if (fscanf(file, "%*c%c-", &replacements_[counter].from) == 0) {
            Error("Incorrect cypher parameter");
        }
        if (fscanf(file, to_int_ ? "%hhu" : "%c", &replacements_[counter].to) == 0) {
            Error("Incorrect cypher parameter");
        }
    }
    int _ = fscanf(file, " "); ++_;
    if (!ValidReplacements()) {
        Error("Cypher is not bijective or has repetitions");
    }
}

void CharEncryption::RandomEncryption(size_t min_param, size_t max_param) {
    size_t count = rand() % (max_param - min_param + 1) + min_param;
    replacement_count_ = count;
    replacements_ = new Replacement[count];
    bool table_1[256];
    bool table_2[256];
    memset(table_1, false, 256);
    memset(table_2, false, 256);
    for (size_t index = 0; index < count; ++index) {
        u_int8_t from;
        do {
            from = Text::RandomSymbol();
        } while (table_1[from]);
        table_1[from] = true;
        u_int8_t to;
        do {
            to = to_int_ ? rand() : Text::RandomSymbol();
        } while (table_2[to]);
        table_2[to] = true;
        replacements_[index] = { from, to };
    }
}

void CharEncryption::Output(FILE *file) const {
    Text::Output(file);
    fprintf(file, "Replacements: %zu (", replacement_count_);
    for (size_t counter = 0; counter < replacement_count_; ++counter) {
        fprintf(file, "%c-", replacements_[counter].from);
        fprintf(file, to_int_ ? "%hhu" : "%c", replacements_[counter].to);
        if (counter != replacement_count_ - 1) {
            fprintf(file, " ");
        }
    }
    fprintf(file, "); Result: ");
    if (!to_int_) {
        fprintf(file, "\"%s\"\n", encrypted_text_);
    } else {
        fprintf(file, "[");
        for (size_t index = 0; index < length_; ++index) {
            fprintf(file, "%u", encrypted_text_[index]);
            if (index != length_ - 1) {
                fprintf(file, " ");
            }
        }
        fprintf(file, "]\n");
    }
}

void CharEncryption::Encrypt() {
    u_int8_t table[256];
    for (int index = 0; index < 256; ++index) {
        table[index] = index;
    }
    for (size_t index = 0; index < replacement_count_; ++index) {
        Replacement replacement = replacements_[index];
        table[replacement.from] = replacement.to;
    }
    encrypted_text_ = new u_int8_t[length_ + 1];
    for (size_t index = 0; index < length_; ++index) {
        encrypted_text_[index] = table[string_[index]];
    }
    encrypted_text_[length_] = '\0';
}

bool CharEncryption::ValidReplacements() const {
    if (replacement_count_ > kMaxReplacements) {
        return false;
    }
    bool table[256];
    for (int check = 0; check < 2; ++check) {
        memset(table, false, 256);
        for (size_t index = 0; index < replacement_count_; ++index) {
            u_int8_t symbol = check == 0 ? replacements_[index].from : replacements_[index].to;
            if (table[symbol]) {
                return false;
            }
            table[symbol] = true;
        }
    }
    return true;
}
