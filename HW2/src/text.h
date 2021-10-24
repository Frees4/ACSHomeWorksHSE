#ifndef __text__
#define __text__

#include <cstdio>

class Text {
 public:
    enum Key { kCharCharEncryption = 1, kShiftEncryption [[maybe_unused]], kCharIntEncryption };
    virtual ~Text();
    [[nodiscard]] double Hash() const;
    static Text *InputText(FILE *file);
    virtual void Input(FILE* file) = 0;
    static Text *RandomText(int cypher, size_t min_length, size_t max_length,
                            size_t min_param, size_t max_param);
    virtual void RandomEncryption(size_t min_param, size_t max_param) = 0;
    virtual void Output(FILE *file) const;
 protected:
    size_t length_;
    unsigned char *string_;
    static unsigned char RandomSymbol();
 private:
    virtual void Encrypt() = 0;
};

#endif //__text__
