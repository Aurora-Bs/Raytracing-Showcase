#include "Position.hpp"
#include <optional>
#include <SDL3/SDL.h>
#include "color.h"
class Ray {
    Position d_origin;
    SDL_Color d_color;
    float d_radius;
    //This must be in radians
    float d_angle;

    public:
    Ray() = delete;
    Ray(Ray&&) = delete;
    Ray(Ray&) __attribute__((unused));
    Ray(Position origin, const SDL_Color color, const float d_radius, const float d_angle);
    Ray operator=(Ray& a) {
        d_origin = a.origin();
        d_color = a.color();
    }
    Position origin();
    SDL_Color color();
    float radius();
    float angle();
    
    void setOrigin(Position& origin);
    void setColor(const SDL_Color color);
    void setRadius(const float dist);
    // std::optional<Position> Ray::at(float x, float y, float z);
    void setAngle(const float rad);
};