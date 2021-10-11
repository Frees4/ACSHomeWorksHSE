#ifndef __text__
#define __text__

#include <cstdio>

struct Text {
  enum Key { kCharCharEncryption = 1, kShiftEncryption, kCharIntEncryption };
  Key key;
  unsigned char *string;
  size_t length;
};

double Hash(const Text &text);

void InputText(FILE *file, Text **out);

Text* RandomText(int cypher, size_t min_length, size_t max_length,
                 size_t min_param, size_t max_param);

void OutputText(FILE* file, const Text& text);

void DeleteText(Text* text);

bool ValidSymbol(unsigned char symbol);

unsigned char RandomSymbol();

#endif //__text__
