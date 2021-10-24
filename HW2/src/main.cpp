#include <cstdio>
#include <ctime>
#include "container.h"
#include <cstdlib>

clock_t start;

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./task input-file output-file\n");
        return 0;
    }
    FILE *in = freopen(argv[1], "r", stdin);
    FILE *out = freopen(argv[2], "w", stdout);
    if (in == nullptr || out == nullptr) {
        fprintf(stderr, "Invalid input/output file");
        return 1;
    }
    atexit([]() { fprintf(stderr, "%f s.", (double) (clock() - start) / CLOCKS_PER_SEC); });
    start = clock();
    Container container{};
    container.Input(in);
    container.Output(out);
    fprintf(out, "\n\n");
    container.MoveFunction(out);
    fclose(in);
    fclose(out);
    return 0;
}
