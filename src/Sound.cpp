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
    // cout<<"entrei em Play";
        if(chunk!=nullptr){
            cout<<"nao é null, devia ta tocando";
            channel= Mix_PlayChannel(channel, chunk, times );

        }else{
            cout<<"chunk nullptr\n";
        }
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
void Sound::Render(){}

void Sound::Update(float dt){}
bool Sound::Is(string type){
    if(type=="Sound"){
        return true;
    }
    return false;
}
