#include <cstdlib>
#include <cstring>
#include "char_encryption.h"
#include "error.h"

void CharEncrypt(CharEncryption *text) {
    u_int8_t table[256];
    for (int index = 0; index < 256; ++index) {
        table[index] = index;
    }
    for (size_t index = 0; index < text->replacement_count; ++index) {
        CharIntReplacement* replacement = &text->replacements.to_int[index];
        table[replacement->from] = replacement->to;
    }
    text->encrypted_text.to_int = new u_int8_t[text->base.length + 1];
    for (size_t index = 0; index < text->base.length; ++index) {
        text->encrypted_text.to_int[index] = table[text->base.string[index]];
    }
    text->encrypted_text.to_int[text->base.length] = '\0';
}

void InputCharEncryption(FILE *file, CharEncryption *text) {
    long count;
    if (fscanf(file, "%zu", &count) == 0 || count < 0) {
        Error("Invalid container parameters");
    }
    text->replacement_count = count;
    text->replacements.to_int = new CharIntReplacement[count];
    for (long counter = 0; counter < count; ++counter) {
        if (fscanf(file, "%*c%c-", &text->replacements.to_int[counter].from) == 0) {
            Error("Incorrect cypher parameter");
        }
        if (text->base.key == Text::kCharCharEncryption) {
            if (fscanf(file, "%c", &text->replacements.to_char[counter].to) == 0) {
                Error("Incorrect cypher parameter");
            }
        } else {
            if (fscanf(file, "%hhu", &text->replacements.to_int[counter].to) == 0) {
                Error("Incorrect cypher parameter");
            }
        }
    }
    int _ = fscanf(file, " "); ++_;
    if (!ValidReplacements(*text)) {
        Error("Cypher is not bijective or has repetitions");
    }
    CharEncrypt(text);
}

bool ValidReplacements(const CharEncryption &text) {
    if (text.replacement_count > kMaxReplacements) {
        return false;
    }
    bool table[256];
    for (int check = 0; check < 2; ++check) {
        memset(table, false, 256);
        for (size_t index = 0; index < text.replacement_count; ++index) {
            u_int8_t symbol = check == 0 ?
                text.replacements.to_int[index].from : text.replacements.to_int[index].to;
            if (table[symbol]) {
                return false;
            }
            table[symbol] = true;
        }
    }
    return true;
}

void RandomCharEncryption(CharEncryption *text, size_t min_param, size_t max_param) {
    size_t count = rand() % (max_param - min_param + 1) + min_param;
    text->replacement_count = count;
    text->replacements.to_int = new CharIntReplacement[count];
    bool table_1[256];
    bool table_2[256];
    memset(table_1, false, 256);
    memset(table_2, false, 256);
    for (size_t index = 0; index < count; ++index) {
        u_int8_t from;
        do {
            from = RandomSymbol();
        } while (table_1[from]);
        table_1[from] = true;
        u_int8_t to;
        do {
            to = text->base.key == Text::kCharCharEncryption ? RandomSymbol() : rand();
        } while (table_2[to]);
        table_2[to] = true;
        text->replacements.to_int[index] = { from, to };
    }
    CharEncrypt(text);
}

void OutputCharEncryption(FILE *file, const CharEncryption &text) {
    fprintf(file, "Replacements: %zu (", text.replacement_count);
    for (size_t counter = 0; counter < text.replacement_count; ++counter) {
        fprintf(file, "%c-", text.replacements.to_int[counter].from);
        if (text.base.key == Text::kCharCharEncryption) {
            fprintf(file, "%c", text.replacements.to_char[counter].to);
        } else {
            fprintf(file, "%hhu", text.replacements.to_int[counter].to);
        }
        if (counter != text.replacement_count - 1) {
            fprintf(file, " ");
        }
    }
    fprintf(file, "); Result: ");
    if (text.base.key == Text::kCharCharEncryption) {
        fprintf(file, "\"%s\"\n", text.encrypted_text.to_char);
    } else {
        fprintf(file, "[");
        for (size_t index = 0; index < text.base.length; ++index) {
            fprintf(file, "%u", text.encrypted_text.to_int[index]);
            if (index != text.base.length - 1) {
                fprintf(file, " ");
            }
        }
        fprintf(file, "]\n");
    }
}

void DeleteCharEncryption(CharEncryption *text) {
    delete[] text->replacements.to_int;
    delete[] text->encrypted_text.to_int;
    delete text;
}
