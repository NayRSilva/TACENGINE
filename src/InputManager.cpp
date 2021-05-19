#include "../include/InputManager.hpp"
#include "SDL2/SDL.h"
#include<iostream>

InputManager::InputManager() {
    quitRequested = false;

    for(int i = 0; i < 6; i++) {
        mouseState[i] = false;
        mouseUpdate[i] = 0;
    }


    updateCounter = 0;
}

InputManager& InputManager::GetInstance() {
    static InputManager inputManager;
    return inputManager;
}

void InputManager::Update(){

	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);
    updateCounter++;
    quitRequested=false;

    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            quitRequested=true;/* constant-expression */:
            /* code */
            break;
        case SDL_MOUSEBUTTONDOWN:

            break;
        
        default:
            break;
        }


    }


}

