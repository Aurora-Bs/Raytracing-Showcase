#include <cmath>
#pragma once
class Position
{
    float d_x;
    float d_y;
    float d_z;
public:
    Position() = delete;
    Position(float x, float y, float z);
    Position(Position&);
    Position(Position&&) = delete;
    Position operator=(Position&);
    float& x();
    float& y();
    float& z();
    //Rotate the position coordinates by `rad` radians along the XY axes around `origin`.
    void XZrotate(float rad, Position* origin);

    //idk if i want this
    float XYrotate(float rad) = delete;
    float YZrotate(float rad) = delete;

    //Transforms the position vector.
    void transform(float x, float y, float z);
    //Transforms the position vector.
    void transform(Position position);

    void moveTo(float x, float y, float z);
    void moveTo(Position destination);
    //Converts `deg` from degrees to radians
    static float toRadians(float deg);

    //Converts `rad` from radians to degrees
    static float toDegrees(float rad);

};