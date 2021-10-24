#ifndef __container__
#define __container__

#include <cstdio>
#include "text.h"

class Container {
 public:
    ~Container();
    void Input(FILE* file);
    void MoveFunction(FILE *file);
    void Output(FILE* file) const;
 private:
    Text** array_;
    size_t length_;
    void GenerateRandom(FILE* file, int seed);
};

#endif //__container__
