#include"../include/Face.hpp"
#include "../include/Sound.hpp"
#include "SDL2/SDL.h"
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>


using std::cout;

Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
    total_time = 1000;
}

void Face::Damage(int damage){
	// auto anteriorframe = std::chrono::steady_clock::now();//pega o tempo quando liga
    // auto currentframe = anteriorframe;
    cout<<"dando Dano\n";
    hitpoints = hitpoints-damage;
    if(hitpoints<=0){
        ///por alguma razão se eu deixo o pinguin por muito tempo e me baseio so no codigo do Game.cpp ele nao faz som
	    firstHit = std::chrono::steady_clock::now();//pega o tempo quando liga

        Sound* sound = reinterpret_cast<Sound*>(associated.GetComponent("Sound"));
        if(sound!=nullptr){
            cout<< "pewpew\n";
            sound->Play(1);
        // SDL_Delay(300);
        }
        // Update(0);

        destroy=true;

    }
}
void Face::Update(float dt){
    // cout<<"imprimir face\n";
	auto currentframe= std::chrono::steady_clock::now();//pega o tempo de agora
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count(); 

    while(diff<total_time){
        currentframe= std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count(); 

    }
    interval = interval+dt;
    // cout<<"face: "<<dt<<"\n";
    if(destroy == true){
        cout<<"destruir \n";
        cout<<dt<<" total:"<<total_time<<"\n";
        // getchar();
        
        if(interval>total_time){
            cout<<"deletou";
            associated.RequestDelete();

        }
    }
}
void Face::Render(){}

bool Face::Is(string type){
    if(type=="Face"){
        return true;
    }
    return false;
}

