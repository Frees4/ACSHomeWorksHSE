#include <cstdlib>
#include <cstdio>
#include "container.h"
#include "error.h"

void InputContainer(FILE *file, Container *container) {
    int input_type;
    long length;
    if (fscanf(file, " %zu %d ", &length, &input_type) < 2 || length < 0) {
        Error("Invalid container parameters");
    }
    container->length = length;
    container->array = new Text*[container->length];
    if (input_type == 0) {
        for (size_t counter = 0; counter < container->length; ++counter) {
            InputText(file, &container->array[counter]);
        }
    } else {
        RandomContainer(file, container, input_type);
    }
}

void RandomContainer(FILE *file, Container *container, int seed) {
    int cypher;
    long min_length;
    long max_length;
    long min_param;
    long max_param;
    if (fscanf(file, "%u %zu %zu %zu %zu", &cypher,
               &min_length, &max_length, &min_param, &max_param) < 5
               || cypher > 3 || min_length > max_length || min_param > max_param
                || min_length < 0 || min_param < 0) {
        Error("Invalid random generator parameters");
    }
    srand(seed);
    for (size_t counter = 0; counter < container->length; ++counter) {
        container->array[counter] =
            RandomText(cypher, min_length, max_length, min_param, max_param);
    }
}

void MoveFunction(Container *container, FILE *file) {
    double sum = 0.0;
    for (int i = 0; i < container->length; i++) {
        sum += Hash(*(container->array[i]));
    }
    double mean = sum / container->length;
    fprintf(file, "Mean: %f\n", mean);
    fprintf(file, "Move Result: \n");
    for (int i = 0; i < container->length; i++) {
        if (Hash(*(container->array[i])) <= mean) {
            OutputText(file, *(container->array[i]));
        }
    }
    for (int i = 0; i < container->length; i++) {
        if (Hash(*(container->array[i])) > mean) {
            OutputText(file, *(container->array[i]));
        }
    }
}

void OutputContainer(FILE *file, const Container &container) {
    fprintf(file, "Container has %zu elements\n", container.length);
    for (size_t index = 0; index < container.length; ++index) {
        fprintf(file, "%zu. ", index + 1);
        OutputText(file, *container.array[index]);
    }
}

void DeleteContainer(const Container &container) {
    for (size_t index = 0; index < container.length; ++index) {
        DeleteText(container.array[index]);
    }
    delete[] container.array;
}
