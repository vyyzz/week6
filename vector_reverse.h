#ifndef VECTOR_REVERSE_H
#define VECTOR_REVERSE_H

#include <vector>
#include <string>

struct int_vector {
    int id;
    int x;
    int y;
};

std::vector<int_vector> readVectorsFromFile(const std::string& filename);
void printVectorsReverse(const std::vector<int_vector>& vectors);

#endif // VECTOR_REVERSE_H
