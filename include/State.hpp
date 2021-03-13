#ifndef _STATE_H_
#define _STATE_H_

#include"Sprite.hpp"

class State{
    public:

        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    private:

    Sprite bg;
    bool quitRequested;
};  

#endif