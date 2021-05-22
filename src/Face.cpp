#include "../include/Face.hpp"
#include "../include/Sound.hpp"
#include "../include/InputManager.hpp"

#include "SDL2/SDL.h"
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>

using std::cout;

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
    total_time = 2000;
}
void Face::Damage(int damage)
{
    // auto anteriorframe = std::chrono::steady_clock::now();//pega o tempo quando liga
    // auto currentframe = anteriorframe;
    cout << "dando Dano\n";
    hitpoints = hitpoints - damage;
    if (hitpoints <= 0)
    {
        ///por alguma razão se eu deixo o pinguin por muito tempo e me baseio so no codigo do Game.cpp ele nao faz som
        // firstHit = std::chrono::steady_clock::now();//pega o tempo quando liga

        Sound *sound = reinterpret_cast<Sound *>(associated.GetComponent("Sound"));
        if (sound != nullptr)
        {
            cout << "pewpew\n";
            sound->Play(1);
            SDL_Delay(300);
        }
        // Update(0);

        destroy = true;
    }
}
void Face::Update(float dt)
{
    // cout<<"imprimir face\n";

    auto currentframe = std::chrono::steady_clock::now(); //pega o tempo de agora
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count();

    while (diff < total_time)
    {
        currentframe = std::chrono::steady_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - firstHit).count();
    }
    interval = interval + dt;
    // cout<<"face: "<<dt<<"\n";
    if (destroy == true)
    {
        // cout<<"destruir \n";
        // cout<<dt<<" total:"<<total_time<<"\n";

        if (interval > total_time)
        {
            associated.RequestDelete();
            // cout<<"deletou";
        }
    }
    else
    {

        InputManager &Iman = InputManager::GetInstance();

        if (Iman.MousePress(SDL_BUTTON_LEFT))
        { //se o botao esquerdo do mouse for pressionado
            int auxX = Iman.GetMouseX();
            int auxY = Iman.GetMouseY();

            if (associated.box.Contains((float)auxX, (float)auxY))
            { //se estiver dentro da box
                cout << "está dentro da caixinhas\n";

                Damage(std::rand() % 10 + 10);
            }
        }
    }
}
void Face::Render() {}

bool Face::Is(string type)
{
    if (type == "Face")
    {
        return true;
    }
    return false;
}
