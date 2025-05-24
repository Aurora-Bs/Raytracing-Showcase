#include "Position.hpp"
#include <SDL3/SDL.h>
#include <concepts>
#include <ranges>
#include <type_traits>
#pragma once
struct IGameObject
{
    const Position d_position;
    const int d_id;
    const SDL_Color d_color;
    virtual Position position() = 0;
    virtual int id() = 0;
    virtual SDL_Color color() = 0;
    virtual void setColor() = 0;
    virtual void setPosition() = 0;
    virtual ~IGameObject() = default;
};

template <typename T>
concept IdSystem_t = requires {
    std::integral<std::decay<std::ranges::range_value_t<T>>> && 
    std::ranges::forward_range<std::decay<T>>;
};
template <IdSystem_t IdSystem>
//A type for cubes, it is up to the user to create an id system.
class Cube : IGameObject{
    float d_l, d_w, d_h;
    IdSystem* const d_idSystem;

    public:
    IdSystem* const idSystem();
    std::tuple<int, int, int> dimensions();

    //The top left position of the cube in the local coordinate system.
    Position position();
    
};

class BaseIdSystem {};