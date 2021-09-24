#include "../include/Minion.hpp"

#include "../include/Alien.hpp"
#include "../include/Sprite.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"
#include "../include/Game.hpp"
#include "time.h"
#include <math.h>
using std::cout;



Minion::Minion(GameObject &associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated){
    Sprite* minioncomp= new Sprite(associated, "assets/img/minion.png");
    arc= arcOffsetDeg;
    alienCenter = alienCenter;
    associated.AddComponent(minioncomp);
    associated.box.w = minioncomp->GetWidth;
    associated.box.h = minioncomp->GetHeight;
    




}

void Minion::Update(float dt){
    if(alienCenter.lock() == nullptr){
        associated.RequestDelete();
    }
    else{
        
        GameObject &alienPosition = *alienCenter.lock.get();
        Vec2 originDistance = Vec2(200, 0);
        float angularVel = PI/10;//2pi é um circulo completo, pensei em fazer 2pi/20 o que da pi/10. Nao entendi se essa constante pode ser dada ou se eu devo considerar mais alguma coisa
        Vec2 rotated = originDistance.Rotate(arc);

        Vec2 aux = alienPosition.box.GetCenter() + originDistance;
        associated.box.SetCenter(aux);

        //update o arc

        if(arc>(2*PI)){//circunferencia é 2pi, se passar dela faz o modulo.
            // float circunferencia = 2*PI;
            arc= arc-(2*PI);
        }else{//aumenta c a velocidade
            float distontime = angularVel*dt;
            arc = arc + distontime; 

        }


    }



}
