#include <SDL3/SDL.h>
#include <tuple>
#include <vector>
class Player
{
    private:
    int base;
    int width;
    int height;
    float center_x;
    float center_y;
    //I don't know if I want this
    float __attribute__((unused)) center_z;
    SDL_Color color;
    Camera playerCamera;

    //This value must be in radians.
    float facing 
    public:
        //Returns the dimensions of the player in order of base, width, and height;
        std::vector<int> dimensions();
        // @returns The position of the player, relativity must be established beforehand.
        std::vector<int> position();
        Player()
    std::vector<Ray> rays;

};