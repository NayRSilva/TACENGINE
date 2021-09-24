#ifndef _STATE_H_
#define _STATE_H_

#include"Sprite.hpp"
// #include"Face.hpp"
#include"Music.hpp"
#include <string>
#include<vector>
using std::string;

class State{
    public:

        State();
        void Start();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
        std::weak_ptr< GameObject > AddObject(GameObject* go);
        std::weak_ptr< GameObject > GetObjectPtr(GameObject* go);

        ~State();

    private:

    vector<std::shared_ptr<GameObject>> objectArray;

    Sprite *bg;
    Music music;
    bool quitRequested;
    bool started;
    // void Input();
    // void AddObject(int mouseX, int mouseY);

};  

#endif