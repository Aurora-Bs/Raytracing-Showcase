#include "Ray.hpp"
#include "Position.hpp"
Ray::Ray(Position origin, const SDL_Color color, const float radius, const float angle) : d_origin(origin), d_color(color), d_radius(radius), d_angle(angle){}
Position Ray::origin() {
    return d_origin;
}

void Ray::setOrigin(Position& origin) {
    d_origin = origin;
}

void Ray::setColor(const SDL_Color color){
    d_color = color;
}

void Ray::setRadius(const float dist){
    d_radius = dist;
}

void Ray::setAngle(const float rad) {
    d_angle = rad;
}

float Ray::radius() {
    return d_radius;
}

float Ray::angle() {
    return d_angle;
}


//Get the position of the ray in each plane at R(X,Y)
// std::optional<Position> Ray::at(float x, float y, float z) {
    // float result = hypotf(X, Y);
// }