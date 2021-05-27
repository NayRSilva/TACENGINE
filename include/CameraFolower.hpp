#ifndef _CF_H_
#define _CF_H_

#include"Component.hpp"
#include <chrono>



class CameraFollower : public Component{
    public:
        CameraFollower(GameObject& go);
        void Update(float dt);
        void Render();
        bool Is(string type);


};

#endif
