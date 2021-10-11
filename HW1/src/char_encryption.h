#ifndef __char_encryption__
#define __char_encryption__

#include "text.h"

static const int kMaxReplacements = 63;

struct CharCharReplacement {
  unsigned char from;
  unsigned char to;
};

struct CharIntReplacement {
  unsigned char from;
  u_int8_t to;
};

struct CharEncryption {
  Text base;
  union {
    CharCharReplacement* to_char;
    CharIntReplacement* to_int;
  } replacements;
  size_t replacement_count;
  union {
    unsigned char* to_char;
    u_int8_t* to_int;
  } encrypted_text;
};

void CharEncrypt(CharEncryption* text);

void InputCharEncryption(FILE* file, CharEncryption* text);

bool ValidReplacements(const CharEncryption& text);

void RandomCharEncryption(CharEncryption* text, size_t min_param, size_t max_param);

void OutputCharEncryption(FILE* file, const CharEncryption& text);

void DeleteCharEncryption(CharEncryption* text);

#endif //__char_encryption__
