#include <vector>
#include <cassert>
#include <optional>
#include <cmath>
namespace vectorMath {
    std::optional<float> vectorLength(std::vector<float> matrix);
    float dotProduct(std::vector<float> A, std::vector<float> B);
}