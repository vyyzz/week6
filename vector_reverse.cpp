#include "vector_reverse.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<int_vector> readVectorsFromFile(const std::string& filename) {
    std::ifstream in_file(filename);
    std::vector<int_vector> vectors;
    int id = 0;
    int x, y;
    
    while (in_file >> x >> y) {
        vectors.push_back({id++, x, y});
    }
    
    in_file.close();
    return vectors;
}

void printVectorsReverse(const std::vector<int_vector>& vectors) {
    int id = vectors.size() - 1;
    for (auto it = vectors.rbegin(); it != vectors.rend(); ++it) {
        std::cout << id-- << ": " << it->x << " " << it->y << std::endl;
    }
}
