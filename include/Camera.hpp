#include "Ray.hpp"
#include <utility>
#include <vector>
#include <SDL3/SDL.h>
#include <map>
// @brief A camera that interperets objects in front of it via raycasting.
// The user can set unit vectors `normalX` and `normalY` to use units `_i` and `_j`
class Camera
{
    int d_FOV;
    int d_renderDistance;
    int d_quality;
    float d_normalX, d_normalZ;
    float d_angle;
    std::vector<Ray> d_rays;
    Position d_position;
    //For Game objects, store their position in a 2D n * n std::vector, where each object is 
    // represented by their object id in the vector.
    // gameObjects should manually load themselves into objectPositions
    std::vector<int, int> objectPositions;
    int nObjects;
    //Using the "I" naming convention for interfaces
    //like in the .NET framework
    std::vector<IGameObject> objectMap;
    
public:
    Camera(Position position, const unsigned int FOV = 60, const int renderDistance = 12, const float normalX = 1, const float normalY = 1, const int quality, const float angle = 0);
    float FOV();
    float renderDistance();
    // Sets the radius to be `rad`
    // @note Ray cannot be negative
    void setNorms(std::pair<float, float> norms);
    std::pair<float, float> norms();
    void setRenderDistance(float dist);
    void quality();
    // Sets the angle of the vector normal to the camera.
    // Draws rays using the cameras local coordinate system and `radius`
    void drawRays();
};