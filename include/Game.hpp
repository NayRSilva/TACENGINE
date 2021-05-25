#ifndef _GAME_H_
#define _GAME_H_

#ifdef INCLUDE_SDL 
	#ifdef _WIN32
		#include <SDL2/SDL.h>
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL.h>
	#elif __linux__
		#include <SDL2/SDL.h>
	#else
		#error "Unknown compiler"
	#endif
	#undef INCLUDE_SDL 
#endif // INCLUDE_SDL

#include <string>
#include "State.hpp"

using std::string;

class Game{
    private:
        string title;
        int width;
        int height;
        SDL_Window* window;
        SDL_Renderer* renderer; 
        Game(string mytitle, int mywidth, int myheight);
        static Game* instance;
        State* state;
        float time;
        int frameStart;
        float dt;
        void CalculateDeltaTime();

    public:
        ~Game();
        static Game& GetInstance();
        State& GetState();
        SDL_Renderer* GetRenderer();
        void Run();
        float GetDeltaTime();
};


#endif