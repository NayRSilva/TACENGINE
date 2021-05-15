#ifndef _STATE_H_
#define _STATE_H_

#include"Sprite.hpp"
#include"Face.hpp"
#include"Music.hpp"
#include <string>
#include<vector>
using std::string;

class State{
    public:

        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        ~State();

    private:

    vector<std::unique_ptr<GameObject>> objectArray;

    Sprite *bg;
    Music music;
    bool quitRequested;
    void Input();
    void AddObject(int mouseX, int mouseY);

};  

#endif