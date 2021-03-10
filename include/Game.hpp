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
using std::string;

class Game{
    private:
        string title;
        int width;
        int height;
        Game(string mytitle, int mywidth, int myheight){//Constructor
            title = mytitle;
            width= mywidth;
            height= myheight;
        }
        static Game* instance;
        

    public:
        ~Game();
        static Game& GetInstance();
};


#endif