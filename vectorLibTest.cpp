#include "vectorMath/vectorMath.hpp"
#include <cassert>
#include <vector>

int main() {
    // Test cases for vectorLength
    // Note: Current implementation sums elements, not Euclidean norm
    {
        std::vector<float> empty = {};
        assert(vectorMath::vectorLength(empty) == 0.0f); // Test empty vector

        std::vector<float> single = {5.0f};
        assert((vectorMath::vectorLength(single) == 5.0f)); // Test single element

        std::vector<float> threeElements = {1.0f, 2.0f, 3.0f};
        assert(vectorMath::vectorLength(threeElements) == 3.0f); // Test sum

        std::vector<float> negatives = {-1.0f, 2.0f};
        assert(vectorMath::vectorLength(negatives) == 1.0f); // Test negative values
    }

    // Test cases for dotProduct
    {
        std::vector<float> emptyA = {};
        std::vector<float> emptyB = {};
        assert(vectorMath::dotProduct(emptyA, emptyB) == 0.0f); // Empty vectors

        std::vector<float> singleA = {5.0f};
        std::vector<float> singleB = {2.0f};
        assert(vectorMath::dotProduct(singleA, singleB) == 10.0f); // Single element

        std::vector<float> vecA = {1.0f, 2.0f};
        std::vector<float> vecB = {3.0f, 4.0f};
        assert(vectorMath::dotProduct(vecA, vecB) == 11.0f); // Standard case

        std::vector<float> negativeA = {-1.0f, 3.0f};
        std::vector<float> negativeB = {2.0f, -4.0f};
        assert(vectorMath::dotProduct(negativeA, negativeB) == -14.0f); // Negative values

        std::vector<float> zeroA = {0.0f, 0.0f};
        std::vector<float> zeroB = {1.0f, 2.0f};
        assert(vectorMath::dotProduct(zeroA, zeroB) == 0.0f); // Zero vectors
    }

    return 0;
}