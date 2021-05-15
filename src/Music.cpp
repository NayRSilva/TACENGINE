#include "../include/Music.hpp"


Music::Music(){
    music=nullptr;
}
Music::Music(string file){
    music=nullptr;
    Open(file);
}

void Music::Play(int times){
    if(music!=nullptr){
        Mix_PlayMusic(music, times);

    }
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
        music = Mix_LoadMUS(file.c_str());
    if(music==nullptr){
		printf("Erro ao carregar musica: %s\n", SDL_GetError());
    }else{

    }
}

bool Music::IsOpen(){
    if(music!=nullptr){
        return true;
    }
    else{
        return false;
    }
}

Music::~Music(){
    Stop(0);
    Mix_FreeMusic(music);
}