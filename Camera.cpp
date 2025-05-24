#include "Camera.hpp"
#include "trignotation.h"
#include <algorithm>
#include <cmath>
#include "spdlog/spdlog.h"
#include <format>
// All operations in this source file must be multiplied by the unit vectors `normalX and `normalY` when possible.
//  @brief The constructor initializes the rays to their respective values, starting from the ray normal to the camera, and branching out from there.
Camera::Camera(Position position, const unsigned int FOV, const int renderDistance, const float normalX, const float normalZ, const int quality = 300, const float angle) : d_position(position), d_FOV(FOV), d_renderDistance(renderDistance), d_normalX(normalX), d_normalZ(normalZ), d_angle(angle), d_quality(quality)
{
    // Initializing the rays
    float angle_max = (FOV / 360.0f) * trignotation::degreesToRadiansConstant;
    for (int i = 0; i <= FOV; i++)
    {
        d_rays.push_back(Ray(
            position,
            SDL_COLOR_GREEN,
            (float)renderDistance,
            angle_max - i * trignotation::degreesToRadiansConstant / FOV)
        );
        std::string msg = std::format("Initialized ray with angle {}", d_rays[i].angle());
        spdlog::debug(msg);
    }

}

float Camera::FOV() {
    return d_FOV;
}

float Camera::renderDistance() {
    return d_renderDistance;
}

void Camera::setNorms(std::pair<float, float> norms){
    d_normalX = norms.first;
    d_normalY = norms.second;

}