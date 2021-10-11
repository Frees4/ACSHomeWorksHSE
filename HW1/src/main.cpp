#include <cstdio>
#include "container.h"
#include "error.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./task input-file output-file\n");
        return 0;
    }
    FILE* in = freopen(argv[1], "r", stdin);
    FILE* out = freopen(argv[2], "w", stdout);
    if (in == nullptr || out == nullptr) {
        Error("Invalid input/output file");
    }
    Container container{};
    InputContainer(in, &container);
    OutputContainer(out, container);
    fprintf(out, "\n\n");
    MoveFunction(&container, out);
    DeleteContainer(container);
    fclose(in);
    fclose(out);
    return 0;
}
