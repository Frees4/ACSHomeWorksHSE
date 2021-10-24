#ifndef __error__
#define __error__

#include <cstdlib>

inline void Error(const char* error) {
    printf("%s\n", error);
    fclose(stdin);
    fclose(stdout);
    exit(1);
}

#endif //__error__
