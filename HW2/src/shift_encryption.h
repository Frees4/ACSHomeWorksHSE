#ifndef __shift_encryption__
#define __shift_encryption__

#include "text.h"

class ShiftEncryption : Text {
 public:
    ~ShiftEncryption() override;
    void Input(FILE* file) override;
    void RandomEncryption(size_t min_param, size_t max_param) override;
    void Output(FILE* file) const override;
 private:
    int shift_;
    unsigned char* encrypted_text_;
    void Encrypt() override;
};

#endif //__shift_encryption__
