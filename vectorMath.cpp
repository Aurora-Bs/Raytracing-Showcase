#include "vectorMath/vectorMath.hpp"
//Gets the vector length of vector `matrix`
//@Return The vector length or -1 if a complex number was obtained.
std::optional<float> vectorMath::vectorLength(std::vector<float> matrix) {
    float preSum = 0;
    for(float i : matrix)
        preSum += powf(matrix[i], 2);
    float result = sqrt(preSum);
    return preSum < 0 ? std::nullopt : std::optional<float>(result);
}

// Gets the dot product of `A` and `B`, throws an error of the vectors are not of the same length
// @cond `A` and `B` must be the same length
float vectorMath::dotProduct(std::vector<float> A, std::vector<float> B){
    assert((A.size() == B.size()));
    float sum = 0;
    for(int i = 0; i < A.size(); i++)
        sum += A[i] * B[i];
    
    return sum;
}