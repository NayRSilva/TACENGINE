#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <chrono>
#include"../include/Resources.hpp"

using std::cout;

#ifdef INCLUDE_SDL_IMAGE 
	#ifdef _WIN32
		#include <SDL2/SDL_image.h>
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_image.h>
	#elif __linux__
		#include <SDL2/SDL_image.h>
	#else
		#error "Unknown compiler"
	#endif
	#undef INCLUDE_SDL_IMAGE 
#endif // INCLUDE_SDL_IMAGE

#ifdef INCLUDE_SDL_MIXER 
	#ifdef _WIN32
		#include <SDL2/SDL_mixer.h>
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_mixer.h>
	#elif __linux__
		#include <SDL2/SDL_mixer.h>
	#else
		#error "Unknown compiler"
	#endif
	#undef INCLUDE_SDL_MIXER 
#endif // INCLUDE_SDL_MIXER

#include "../include/Game.hpp"

Game* Game::instance;

Game& Game::GetInstance(){
    if(instance == nullptr){
        instance = new Game("The Game", 1024, 600);
    }
    return *instance;
}

Game::Game(string title, int width, int height){
	
	if(instance == nullptr){
        instance = this;
    }else{
		exit(EXIT_FAILURE);
	}

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)!=0){//If failure on SDL
		printf("Problema ao inicializar SDL: %s\n", SDL_GetError());	
	}else{//If success
		cout << "Sucesso no SDL, inicializando...\n";
		if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)==0){
			cout<<"erro ao carregar img_init";
		};
		Mix_Init(MIX_INIT_MP3);
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
		  int Mix_audioError = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

		Mix_AllocateChannels(32);
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

		if(window!=nullptr){
			cout<<"Window created\n";
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}else{
			printf("Erro ao criar janela: %s\n", SDL_GetError());
		}

		if(renderer!=nullptr){
			state = new State();
			cout<<"render created\n";
			
		}else{
			printf("Erro ao criar render: %s\n", SDL_GetError());
		}
	}

}
Game::~Game(){
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_Quit();


}

State& Game::GetState(){
	return *state;
}

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}

void Game::Run(){
		// getchar();
	
	//1- verifica controla e carrega as telas

	//2- Os dados de input sao recebidos e processados

	//3 os objetos tem estados
	//4 objetos sao desenhados
	//pega o tempo de agora, steady é o relógio pra fazer comparação de tempo
	auto anteriorframe = std::chrono::steady_clock::now();//pega o tempo quando liga
	auto currentframe = anteriorframe;//salva esse valor
	state->Update(0);


	
	while(!(state->QuitRequested())){

		anteriorframe = currentframe;//troca p manter o tempo anterior atualizado
		currentframe= std::chrono::steady_clock::now();//pega o tempo de agora
		// std::chrono::steady_clock::time_point cf (currentframe);
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(currentframe - anteriorframe).count(); 
		// float teste = diff.count();
		// cout<<teste<<"\n";
		// getchar();
		state->Update((float) diff);

		state->Render();
		SDL_RenderPresent(renderer);

		auto newcurrentframe= std::chrono::steady_clock::now();//pega o tempo de agora
		auto diff2 = std::chrono::duration_cast<std::chrono::milliseconds>(newcurrentframe - currentframe).count(); 
		SDL_Delay(30);
		SDL_Delay(diff2);



		// Uint32 currenttime = (Uint32) calculo;

	}
		Resources::ClearImages();
		Resources::ClearMusics();
		Resources::ClearSounds();

}