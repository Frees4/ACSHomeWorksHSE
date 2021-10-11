#ifndef __shift_encryption__
#define __shift_encryption__

#include "text.h"

struct ShiftEncryption {
  Text base;
  int shift;
  char* encrypted_text;
};

void ShiftEncrypt(ShiftEncryption* text);

void InputShiftEncryption(FILE* file, ShiftEncryption* text);

void RandomShiftEncryption(ShiftEncryption* text, size_t min_param, size_t max_param);

void OutputShiftEncryption(FILE* file, const ShiftEncryption& text);

void DeleteShiftEncryption(ShiftEncryption* text);

#endif //__shift_encryption__
