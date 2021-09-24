
#include "../include/Alien.hpp"
#include "../include/Sprite.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"
#include "../include/Game.hpp"
#include "time.h"
#include <math.h>
using std::cout;


Alien::Action::Action(Alien::Action::ActionType typeac, float x, float y){
    type = typeac;
    pos.x = x;
    pos.y = y;
}

Alien::Alien(GameObject &associated, int nMinions) : Component(associated){
    Sprite* alienSp= new Sprite(associated, "assets/img/alien.png");
    hp=100;
    speed.x=100;
    speed.y=100;
    associated.AddComponent(alienSp);
    associated.box.w= alienSp->GetWidth();
    associated.box.h= alienSp->GetHeight();




}

Alien::~Alien(){
    minionArray.clear();

}

void Alien::Start(){

}

void Alien::Update(float dt){
    InputManager& Iman = InputManager::GetInstance();
    // cout<<"alien update\n\n";
    if(Iman.MousePress(SDL_BUTTON_LEFT)){
        Action *newact = new Action(Action::SHOOT, (Camera::pos.x+Iman.GetMouseX()), (Camera::pos.y+Iman.GetMouseY()) );
        taskQueue.push(*newact);


        //tiro
    }
    else if(Iman.MousePress(SDL_BUTTON_RIGHT)){

        Action *newact = new Action(Action::MOVE, (Camera::pos.x+Iman.GetMouseX()), (Camera::pos.y+Iman.GetMouseY()) );
        taskQueue.push(*newact);
        
        //try this https://gamedev.stackexchange.com/questions/48119/how-do-i-calculate-how-an-object-will-move-from-one-point-to-another

        //move
    }

    if(!taskQueue.empty()){
        Action action = taskQueue.front();
        float cspeed = 200;
        

        if(action.type == Action::MOVE){

            float distance;
            

            Vec2 myOldPosition= Vec2(associated.box.x, associated.box.y);
            distance = Vec2::GetHipo(action.pos, myOldPosition);//é o triangulo.
            Vec2 NormalizedVec = Vec2::Normalize(myOldPosition, action.pos);
            float variacaoEspaco = cspeed*dt;//multiplico minha velocidade (km/tempo) pelo dt que é o intervalo de tempo de update e consigo a distancia que eu movo por tempo

            cout<< variacaoEspaco <<" espaço";
            if(distance<variacaoEspaco){
                taskQueue.pop();
                associated.box.y = action.pos.y;//posiçoes finais
                associated.box.x = action.pos.x;//posicoes finais

            }else{
                float ratio = variacaoEspaco/distance;//eu nao entendi pq aqui é variavçao espaço qmas se nao fosse isso o alien ficava dançando na tela. Suponho que seja o dt, mas na minha cabeça era velocidade/distnacia
                float movementX= ratio * (action.pos.x - myOldPosition.x);//isso fazia sentido ha dez minutos atras. Se eu pegar a diferença da minha posiçao horizontal antiga com a nova eu tenho a variação que eu quero, se eu multiplicar isso pelo ratio eu tenho algo da forma ratio = v*t/d  (v*t/d) *d = v*t e a formula da velocidade é v = d/t logo d= v*t... eu acho que é isso.
            
                float movementY= ratio*(action.pos.y - myOldPosition.y);
                associated.box.y += movementY;//atualiza o valor da posiçao de associated box pq quando entrar em update de novo vamos ter uma diferença menor
                associated.box.x += movementX;
                //nao pop pq a gente ta num loop que so vai pop quando distance<variaçao que eu for fazer

            }




            
        }
        else{
            if(action.type == Action::SHOOT){
                taskQueue.pop();
            }
        }

    }

    if(hp<0){
        associated.RequestDelete();
    }
}

void Alien::Render(){

}

bool Alien::Is(string type){

    if(type=="Alien") return true;
    else return false;
}