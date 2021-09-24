#include "../include/Camera.hpp";
#include "../include/InputManager.hpp";
#include "SDL2/SDL.h";

using std::cout;


GameObject* Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;


void Camera::Follow(GameObject* newFocus){
    focus= newFocus;
}

void Camera::Unfollow(){
    focus= nullptr;
}

void Camera::Update(float dt){
    // cout<<"camera update\n";
    if(focus==nullptr){//se não
    InputManager& Iman = InputManager::GetInstance();

    speed.x = 100;
    speed.y = 100;
    
    if(Iman.IsKeyDown(RIGHT_ARROW_KEY)){
        cout<<"pra direita\n";
        pos.x = pos.x + (speed.x * dt);
    }
    if(Iman.IsKeyDown(LEFT_ARROW_KEY)){
        cout<<"pra esquerda\n";

        pos.x = pos.x - (speed.x * dt);
        cout<<"pox "<<pos.x<<"\n";

    }
    if(Iman.IsKeyDown(UP_ARROW_KEY)){
        pos.y = pos.y - (speed.y * dt);

    }
    if(Iman.IsKeyDown(DOWN_ARROW_KEY)){
        pos.y = pos.y + (speed.y * dt);

    }

    }else{//se tiver um foco
        cout<<"nao temos foco";
        pos.x = 1024/2 + focus->box.x;
        pos.y = 600/2 + focus->box.y;
    }
}