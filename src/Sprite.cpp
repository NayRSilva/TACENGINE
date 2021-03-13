#include <SDL2/SDL_image.h>
#include"../include/Sprite.hpp"
#include"../include/Game.hpp"
#include <iostream>

using std::cout;

Sprite::Sprite(){
    texture= nullptr;
}

Sprite::Sprite(string file){
    texture = nullptr;
    Open(file);
    // if(IsOpen()){
    //     cout<<"textura aberta";
    // }
}

Sprite::~Sprite(){
    if(texture!=nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(string file){
    if(texture!=nullptr){
        SDL_DestroyTexture(texture);
    }

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    texture = IMG_LoadTexture(renderer, file.c_str());
    if(texture==nullptr){
		printf("Erro ao criar imagem: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }else{
        if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)==0){
        SetClip(0,0, width, height);

        }else{
		printf("Erro na querytexture: %s\n", SDL_GetError());
            
        };
    }

}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x= x;
    clipRect.y= y;
    clipRect.w=w;
    clipRect.h=h;
}

int Sprite::GetWidth(){
    return clipRect.w;
}
int Sprite::GetHeight(){
    return clipRect.h;
}
void Sprite::Render(int x, int y){
    // printf("width height %d %d",x,y);

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();


    SDL_Rect dst;
    dst.x= x;
    dst.y= y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;
    if(texture!=nullptr){
            if(SDL_RenderCopy(renderer, texture, &clipRect, &dst)==0){
        cout<<"Success";
    }else{
		printf("Erro no render copy: %s\n", SDL_GetError());

    };

    }


}

bool Sprite::IsOpen(){
    if(texture!=nullptr){
        return true;
    }else{ return false;};
}