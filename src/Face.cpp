#include"../include/Face.hpp"
#include "../include/Sound.hpp"
#include "SDL2/SDL.h"
#include <iostream>
#include <string>


using std::cout;

Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage){
    cout<<"dando Dano\n";
    hitpoints = hitpoints-damage;
    if(hitpoints<0){
        Sound* sound = reinterpret_cast<Sound*>(associated.GetComponent("Sound"));
        if(sound!=nullptr){
            cout<< "pewpew\n";
            sound->Play();
            SDL_Delay(100);
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

