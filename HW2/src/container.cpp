#include <cstdio>
#include "container.h"
#include "error.h"
#include "text.h"

Container::~Container() {
    for (size_t index = 0; index < length_; ++index) {
        delete array_[index];
    }
    delete[] array_;
}

void Container::Input(FILE* file) {
    int input_type;
    long length;
    if (fscanf(file, " %zu %d ", &length, &input_type) < 2 || length < 0) {
        Error("Invalid container parameters");
    }
    length_ = length;
    array_ = new Text*[length_];
    if (input_type == 0) {
        for (size_t counter = 0; counter < length_; ++counter) {
            array_[counter] = Text::InputText(file);
        }
    } else {
        GenerateRandom(file, input_type);
    }
}

void Container::MoveFunction(FILE *file) {
    double sum = 0.0;
    for (int i = 0; i < length_; i++) {
        sum += array_[i]->Hash();
    }
    double mean = sum / length_;
    fprintf(file, "Mean: %f\n", mean);
    fprintf(file, "Move Result: \n");
    for (int i = 0; i < length_; i++) {
        if (array_[i]->Hash() <= mean) {
            array_[i]->Output(file);
        }
    }
    for (int i = 0; i < length_; i++) {
        if (array_[i]->Hash() > mean) {
            array_[i]->Output(file);
        }
    }
}

void Container::Output(FILE *file) const {
    fprintf(file, "Container has %zu elements\n", length_);
    for (size_t index = 0; index < length_; ++index) {
        fprintf(file, "%zu. ", index + 1);
        array_[index]->Output(file);
    }
}

void Container::GenerateRandom(FILE *file, int seed) {
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
    for (size_t counter = 0; counter < length_; ++counter) {
        array_[counter] = Text::RandomText(cypher, min_length, max_length, min_param, max_param);
    }
}
