#include"../include/Sound.hpp"
#include <iostream>

using std::cout;

Sound::Sound(GameObject& associated) : Component(associated){
  chunk= nullptr;  

}

Sound::Sound(GameObject& associated, string file) : Component(associated){
  Open(file);

}

void Sound::Play(int times){
    int aux= (-1);
    channel= Mix_PlayChannel(aux, chunk, times );
}

void Sound::Stop(){
    if(chunk!=nullptr){
        Mix_HaltChannel(channel);

    }
}
bool Sound::IsOpen(){
    if(chunk!=nullptr){
        return true;
    }
    return false;

}


void Sound::Open(string file){
    chunk = Mix_LoadWAV(file.c_str());

    if(!IsOpen()){
        cout<<"Erro no chunk: "<<SDL_GetError()<<"\n";
    }

}

Sound::~Sound(){
    if(chunk!=nullptr){
        Stop();
        Mix_FreeChunk(chunk);
    }
}
