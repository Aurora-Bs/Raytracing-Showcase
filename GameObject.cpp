#include "GameObject.hpp"
template<IdSystem_t IdSystem>
IdSystem* const Cube::idSystem  ()  {
    return d_idSystem;
}
Position Cube::position() {
    return d_position;
}