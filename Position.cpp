#include "Position.hpp"
#include "trignotation.h"

Position::Position(float x, float y, float z) {
    d_x = x;
    d_y = y;
    d_z = z;
}
Position::Position(Position& position) {
   d_x = position.d_x;
   d_y = position.d_y;
   d_z = position.d_z;
}

Position Position::operator=(Position& position){
   d_x = position.d_x;
   d_y = position.d_y;
   d_z = position.d_z;
}
float& Position::x() {
    return d_x;
}
float& Position::y() {
    return d_y;
}
float& Position::z() {
    return d_z;
}

void Position::transform(float x, float y, float z) {
    d_x += x;
    d_y += y;
    d_z += z;
}

void Position::XZrotate(float rad, Position* origin) {
    d_x = origin->x() * cosf(rad);
    d_z = origin->z() * sinf(rad);
}

float Position::toRadians(const float deg) {
    return deg * trignotation::degreesToRadiansConstant;
}

float Position::toDegrees(const float rad) {
   return rad * trignotation::radiansToDegreesConstant;
}