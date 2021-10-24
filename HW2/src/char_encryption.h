#ifndef __char_encryption__
#define __char_encryption__

#include <cstdlib>
#include "text.h"

static const int kMaxReplacements = 63;

struct Replacement {
  unsigned char from;
  u_int8_t to;
};

class CharEncryption : Text {
 public:
    CharEncryption(bool to_int);
    ~CharEncryption() override;
    void Input(FILE* file) override;
    void RandomEncryption(size_t min_param, size_t max_param) override;
    void Output(FILE* file) const override;
 private:
    bool to_int_;
    Replacement* replacements_;
    size_t replacement_count_;
    u_int8_t* encrypted_text_;
    void Encrypt() override;
    [[nodiscard]] bool ValidReplacements() const;
};

#endif //__char_encryption__
