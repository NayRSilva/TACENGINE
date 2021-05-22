#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <unordered_map>
#include <iostream>
#include "Sprite.hpp"

using std::string;
using std::unordered_map;


class Resources{
    public: 
        static SDL_Texture * GetImage(string file);
        static void ClearImages();
        static Mix_Music* GetMusic(string file);
        static void ClearMusics();
        static Mix_Chunk* GetSound(string file);
        static void ClearSounds();
        static SDL_Texture* createTexture(string file);

    private:
        static unordered_map<string, SDL_Texture*> imageTable;
        static unordered_map<string, Mix_Music*> musicTable;
        static unordered_map<string, Mix_Chunk*> soundTable;

};

#endif
