#include"../include/Face.hpp"
#include "../include/Sound.hpp"
#include "SDL2/SDL.h"

Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints = hitpoints-damage;
    if(hitpoints<0){
        Sound* sound = reinterpret_cast<Sound*>(associated.GetComponent("Sound"));
        if(sound!=nullptr){
            sound->Play();
        }
        associated.RequestDelete();
    }
}
void Face::Update(float dt){}
void Face::Render(){}

bool Face::Is(string type){
    if(type=="Face"){
        return true;
    }
    return false;
}

