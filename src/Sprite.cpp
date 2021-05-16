#include <SDL2/SDL_image.h>
#include"../include/Sprite.hpp"
#include"../include/Game.hpp"
#include <iostream>
#include"../include/Resources.hpp"

using std::cout;

Sprite::Sprite(GameObject& associated) : Component(associated){
    texture= nullptr;
}

Sprite::Sprite(GameObject& associated, string file): Component(associated){
    
    texture = nullptr;
    Open(file);
    if(IsOpen()){
        cout<<"textura aberta";
    }
}

// Sprite::Sprite(string file):texture(IMG_LoadTexture(
//         Game::GetInstance().GetRenderer(),
//         file.c_str()    )){
    
//     // texture = nullptr;
//     Open(file);
//     // if(IsOpen()){
//     //     cout<<"textura aberta";
//     // }
// }

Sprite::~Sprite(){
    // if(texture!=nullptr){
    //     SDL_DestroyTexture(texture);
    // }
}

void Sprite::Open(string file){
    texture = Resources::GetImage(file);
    // if(texture!=nullptr){
    //     SDL_DestroyTexture(texture);
    // }


    // texture = IMG_LoadTexture(renderer, file.c_str());
    // SDL_Surface* surface= IMG_Load(file.c_str());
    // texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(texture==nullptr){
		printf("Erro ao criar imagem: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }else{
        if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)==0){
            SetClip(0,0, width, height);

        }else{
		    printf("Erro na querytexture: %s\n", SDL_GetError());
            // getchar();
            
        }
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
void Sprite::Render(){

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();


    SDL_Rect dst;
    dst.x= associated.box.x;
    dst.y= associated.box.y;
    dst.w = GetWidth();
    dst.h = GetHeight();
    // printf("x y %d %d",dst.x,dst.y);
    if(texture!=nullptr){
            if(SDL_RenderCopy(renderer, texture, &clipRect, &dst)==0){
        // cout<<"Success";
        // getchar();
    }else{
		printf("Erro no render copy: %s\n", SDL_GetError());

    };

    }


}

void Sprite::Render(float a, float b){

    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();


    SDL_Rect dst;

    dst.x = a;
    dst.y = b;
    dst.w = GetWidth();
    dst.h = GetHeight();

    if(texture!=nullptr){
            if(SDL_RenderCopy(renderer, texture, &clipRect, &dst)==0){
        // cout<<"Success";
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

void Sprite::Update(float dt){

}

bool Sprite::Is(string type){
    if(type=="Sprite"){ 
        return true;
        }
    return false;
}