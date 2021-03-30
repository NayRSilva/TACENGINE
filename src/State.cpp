#include "../include/State.hpp"
#include "SDL2/SDL.h"
#include"../include/Face.hpp"
#include"../include/Vec2.hpp"
#include"../include/Sound.hpp"

#include <iostream>

using std::cout;

State::State(){
    quitRequested = false;

	GameObject *go= new GameObject();
	go->box.x= 0;
	go->box.y= 0;
	
	bg = new Sprite(*go, "assets/img/ocean.png");
	go->box.w= bg->GetWidth();
	go->box.h= bg->GetHeight();
	go->AddComponent(bg);
	objectArray.emplace_back(go);
    // bg= Sprite("assets/img/ocean.jpg");


}

State::~State(){
    objectArray.clear();
}



void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.


				if(go->box.Contains((float)mouseX, (float)mouseY) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( (-PI + PI*(rand() % 1001)/500.0) ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}




void State::LoadAssets(){

}

void State::Update(float dt){
		// getchar();
	unsigned int aux= objectArray.size();
	Input();
	
	for(unsigned int i = 0; i < aux; i++) {
		objectArray[i]->Update(0);
	}

	for(int unsigned i = 0; i < objectArray.size(); i++) {
		if(objectArray[i]->IsDead()){
			objectArray.erase(objectArray.begin()+i);
			i--;
		}
	}
 

}

bool State::QuitRequested(){
    // cout<<"Teste quitrequested";
    // getchar();
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
	cout<<"Adicionando Objeto\n";
	GameObject *firstEnemy= new GameObject();
	firstEnemy->box.x= mouseX;
	firstEnemy->box.y= mouseY;
	
	Sprite *penguin = new Sprite(*firstEnemy, "assets/img/penguinface.png");
	firstEnemy->box.w= penguin->GetWidth();
	firstEnemy->box.h= penguin->GetHeight();
	firstEnemy->AddComponent(penguin);
	Sound *dieSound= new Sound(*firstEnemy, "assets/img/boom.wav");
	firstEnemy->AddComponent(dieSound);
	Face *penguinFace= new Face(*firstEnemy);
	firstEnemy->AddComponent(penguinFace);

	objectArray.emplace_back(firstEnemy);


}
