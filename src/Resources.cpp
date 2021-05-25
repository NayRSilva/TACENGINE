#include "../include/Resources.hpp"
#include "../include/Game.hpp"

using std::string;
using std::cout;
using std::unordered_map;

unordered_map<std::string, SDL_Texture*> Resources::imageTable;
unordered_map<std::string, Mix_Music*> Resources::musicTable;
unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::createTexture(string file){
    
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    SDL_Texture* texture = nullptr; 
    texture = IMG_LoadTexture(renderer, file.c_str());
    //     SDL_Surface* surface= IMG_Load(file.c_str());
    // texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture==nullptr){
        cout<<"erro ao criar";
        
    }


    return texture;


}


SDL_Texture* Resources::GetImage(string file){
    if(imageTable.find(file)==imageTable.end()){//se for igual é porque nao existe
        cout<<"primeira vez na tabela\n";
        // cout<<file<<"\n";
        SDL_Texture* texture = createTexture(file);

        if(texture==nullptr){
            printf("Erro ao criar imagem: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }else{
            cout<<"\nimagem not null \n";
            imageTable[file]= texture;
            

        }


        return texture;

    }else{
        cout<<file<<"\n imagem já existe\n";


        return imageTable[file];
    }

}

Mix_Chunk* Resources::GetSound(string file){
    if(soundTable.find(file)==soundTable.end()){//se for igual é porque nao existe
        Mix_Chunk* chunk = Mix_LoadWAV(file.c_str());

        if(chunk==nullptr){
            printf("Erro ao criar som: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }else{
            soundTable[file]= chunk;

        }

        // return soundTable[file];

    }else{
        cout<<"som já existe\n";
        // return soundTable[file];
    }

        return soundTable[file];


}

Mix_Music* Resources::GetMusic(string file){
    if(musicTable.find(file)==musicTable.end()){//se for igual é porque nao existe
        Mix_Music* music = Mix_LoadMUS(file.c_str());

        if(music==nullptr){
            printf("Erro ao criar musica: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }else{
            musicTable[file]= music;

        }

        return musicTable[file];

    }else{
        cout<<"musica já existe\n";
        return musicTable[file];
    }

}

void Resources::ClearImages(){
    for(auto im: imageTable){
        SDL_DestroyTexture(im.second);
    }

    imageTable.clear();
}

void Resources::ClearMusics(){
    for(auto mus: musicTable){
        Mix_FreeMusic(mus.second);
    }

    musicTable.clear();
}

void Resources::ClearSounds(){
    for(auto sound: soundTable){
        Mix_FreeChunk(sound.second);
    }

    soundTable.clear();
}
