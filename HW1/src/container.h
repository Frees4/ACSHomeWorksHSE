#ifndef __container__
#define __container__

#include "text.h"

struct Container {
  Text** array;
  size_t length;
};

void InputContainer(FILE* file, Container* container);

void RandomContainer(FILE* file, Container* container, int seed);

void MoveFunction(Container* container, FILE *file);

void OutputContainer(FILE* file, const Container& container);

void DeleteContainer(const Container& container);

#endif //__container__
