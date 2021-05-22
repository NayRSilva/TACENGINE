#include "../include/State.hpp"
#include "SDL2/SDL.h"
#include"../include/Face.hpp"
#include"../include/Vec2.hpp"
#include"../include/Sound.hpp"
#include"../include/TileSet.hpp"
#include"../include/TileMap.hpp"
#include"../include/InputManager.hpp"

#include <iostream>

using std::cout;

State::State() {
    quitRequested = false;
	// music.Play(-1);


	GameObject *go= new GameObject();
	go->box.x= 0;
	go->box.y= 0;

	
	bg = new Sprite(*go, "assets/img/ocean.jpg");


	go->box.w= bg->GetWidth();
	go->box.h= bg->GetHeight();

	go->AddComponent(bg);
	objectArray.emplace_back(go);

	go = new GameObject();
	
		go->box.x= 0;
	go->box.y= 0;
	TileSet *tileSet= new TileSet(64, 64, "assets/img/tileset.png");
	TileMap *tileMap = new TileMap(*go,"assets/map/tileMap.txt", tileSet);
	go->AddComponent(tileMap);
	objectArray.emplace_back(go);




    // bg= Sprite("assets/img/ocean.jpg");
	// music = new Music("assets/audio/stageState.ogg");



}

State::~State(){
    objectArray.clear();
}




void State::LoadAssets(){

}

void State::Update(float dt){

	InputManager& Iman = InputManager::GetInstance();

	if(Iman.IsKeyDown(ESCAPE_KEY)||(Iman.QuitRequested())){
		quitRequested= true;
	}

	if(Iman.IsKeyDown(SDLK_SPACE)){

		Vec2 objPos = Vec2( 200, 0 ).GetRotated( (-PI + PI*(rand() % 1001)/500.0) ) + Vec2( Iman.GetMouseX(), Iman.GetMouseY());
		AddObject((int)objPos.x, (int)objPos.y);
	}

	unsigned int aux= objectArray.size();
	
	for(unsigned int i = 0; i < aux; i++) {
		objectArray[i]->Update(dt);
	}
	
	
	for(int unsigned i = 0; i < objectArray.size(); i++) {
		if(objectArray[i]->IsDead()){	

				cout<<"\n array size: ";
				cout<<(objectArray.size())<<"\n";
				objectArray.erase(objectArray.begin()+i);
				i--;
						cout<<i<< " is dead \n";


		}
	}

 

}

bool State::QuitRequested(){
    // cout<<"Teste quitrequested";
    return quitRequested;
}

void State::Render(){
    // cout<<"devia abrir";
	unsigned int aux= objectArray.size();
	
	for(unsigned int i = 0; i < aux; i++) {
		objectArray[i]->Render();
	}


//    bg.Render(0,0);
}

void State::AddObject(int mouseX, int mouseY){
	cout<<"\nAdicionando Objeto\n";


	GameObject *firstEnemy= new GameObject();
	firstEnemy->box.x= mouseX;
	firstEnemy->box.y= mouseY;

	
	Sprite *penguin = new Sprite(*firstEnemy, "assets/img/penguinface.png");
	firstEnemy->box.w= penguin->GetWidth();
	// cout<<"\n width:" << (penguin->GetWidth());
	firstEnemy->box.h= penguin->GetHeight();


	Sound *dieSound= new Sound(*firstEnemy, "assets/audio/boom.wav");


	Face *penguinFace= new Face(*firstEnemy);

	firstEnemy->AddComponent(penguin);
	firstEnemy->AddComponent(dieSound);
	
	firstEnemy->AddComponent(penguin);
	firstEnemy->AddComponent(dieSound);
	firstEnemy->AddComponent(penguinFace);

	objectArray.emplace_back(firstEnemy);
	cout<<"emplaced enemy\n";


}
