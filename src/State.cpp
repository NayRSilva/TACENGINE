#include "../include/State.hpp"
#include "SDL2/SDL.h"
#include <iostream>

using std::cout;

State::State():bg("assets/img/ocean.jpg"){
    quitRequested = false;
    // bg= Sprite("assets/img/ocean.jpg");


}

void State::LoadAssets(){

}

void State::Update(float dt){
		// getchar();

    if(SDL_QuitRequested()){
        quitRequested=true;
    }

}

bool State::QuitRequested(){
    // cout<<"Teste quitrequested";
    // getchar();
    return quitRequested;
}

void State::Render(){
    // cout<<"devia abrir";
   bg.Render(0,0);
}

