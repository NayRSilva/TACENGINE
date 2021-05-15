#ifndef _FACE_H_
#define _FACE_H_

#include"Component.hpp"
#include "../include/Sound.hpp"
#include <chrono>



class Face : public Component{
    public:
        Face(GameObject& associated);
        void Damage(int damage);
        void Update(float dt);
        void Render();
        bool Is(string type);

    private:
        int hitpoints;
        bool destroy = false;
        float interval;
        float total_time;
        std::chrono::steady_clock::time_point firstHit;


};

#endif
