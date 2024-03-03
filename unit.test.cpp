#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector_reverse.h"

TEST_CASE("Vector Reverse") {
    SUBCASE("Read Vectors From File") {
        std::string filename = "test_vectors.txt"; 
        std::ofstream outfile(filename);
        outfile << "1 2\n"
                << "3 4\n"
                << "5 6\n";
        outfile.close();

        std::vector<int_vector> vectors = readVectorsFromFile(filename);
        REQUIRE(vectors.size() == 3);
        CHECK(vectors[0].id == 0);
        CHECK(vectors[0].x == 1);
        CHECK(vectors[0].y == 2);
        CHECK(vectors[1].id == 1);
        CHECK(vectors[1].x == 3);
        CHECK(vectors[1].y == 4);
        CHECK(vectors[2].id == 2);
        CHECK(vectors[2].x == 5);
        CHECK(vectors[2].y == 6);

        
        std::remove(filename.c_str());
    }

    SUBCASE("Print Vectors Reverse") {
        std::vector<int_vector> vectors = {
            {0, 1, 2},
            {1, 3, 4},
            {2, 5, 6}
        };

        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); 
        std::string output = buffer.str();

        CHECK(output == "2: 5 6\n1: 3 4\n0: 1 2\n");
        
        std::cout.rdbuf(old);
    }
}
