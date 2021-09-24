#ifndef _minion_H_
#define _minion_H_

#include"Component.hpp"
#include"Vec2.hpp"
#include <queue>
using std::string;
using std::queue;



class Minion : public Component{
    public:
        Minion(GameObject &associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);
        void Update(float dt);
        void Render();
        bool Is(string type);
        void Shoot(Vec2 target);

    private:
       std::weak_ptr<GameObject> alienCenter;
       float arc;



};

#endif
