#ifndef _RECT_H_
#define _RECT_H_

#include"../include/Vec2.hpp"
class Rect{
    public: 
        float x, y, w, h;
        bool Contains(float mouseX, float mouseY);
        Vec2 GetCenter();
        void Rect::SetCenter(Vec2 vector)
        


};

#endif
