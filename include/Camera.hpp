#ifndef _CAM_H_
#define _CAM_H_

#include <SDL2/SDL.h>
#include "SDL2/SDL_mixer.h"
#include "GameObject.hpp"
#include "Vec2.hpp"


using std::string;


class Camera{
    public: 

    static void Follow(GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);
    static Vec2 pos;
    static Vec2 speed;

    private:
    static GameObject* focus;

};

#endif
