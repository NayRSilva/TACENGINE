#include <fstream>
#include <sstream>      // std::istringstream
#include "../include/TileMap.hpp"



using namespace std;


TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated){
    Load(file);
    SetTileSet(tileSet);
}


void removeSpaceBeginEnd(string &line){
  string regex= " \n\t\f\v\r";
  //apaga qualquer coisa antes de uma caractere
  size_t lineposition;
  lineposition= line.find_first_not_of(regex);
    if(lineposition <= line.length()){
      line.erase(0, lineposition);
    }
  //acha a ultima coisa que nao é um espaço e apaga a partir daí
  lineposition = (line.find_last_not_of(regex))+1;
  if(lineposition <= line.length()){
    line.erase(lineposition, string::npos);
  }

}
void splitToVector1(string line, vector<int> &tokens){
      string regex= " \n\t\f\v\r";//acha o primeiro que não for espaço
      size_t  lineposition= line.find_first_not_of(regex);

        if(lineposition <= line.length()){//se a linha tiver algum caractere

                istringstream auxstring(line);
                string token;
                int auxint;
                cout<<"Lendo o mapa: \n";
                while(getline(auxstring, token, ',')){
                    cout<<token<<" foi o token\n";
                    if(token=="\n"){
                        cout<<"ola\n";
                    // getchar();
                    }
                    auxint= atoi(token.c_str());
                    cout<<auxint<<"\n";
                    tokens.push_back(auxint);
                }

        }

}
void splitToVector(string line, vector<int> &tokens){
    cout<<"entrou\n";
    // getchar();
    
    


                istringstream auxstring(line);
                string token;
                int auxint;
                cout<<"Lendo o mapa: \n";
                while(getline(auxstring, token, ',')){
                    auxint= atoi(token.c_str());
                    auxint--;
                    cout<<auxint<<"\n";
                    tokens.push_back(auxint);
                }

        



}

void TileMap::Load(string file){
    ifstream mapfile; //arquivo original, leitura
    mapfile.open(file);
    int numberline=1;
        string linha;
    if(!mapfile.is_open()){
            cout << "Não foi possível abrir o arquivo de mapa \n";

    }else{
        while(getline(mapfile, linha)){
            vector<int> tokens;
                removeSpaceBeginEnd(linha);

            if(numberline==1){
                splitToVector1(linha, tokens );

                mapWidth = tokens[0];
                mapHeight = tokens[1];
                mapDepth = tokens[2];
                    cout<<"vetor\n";
                for(auto t:tokens){
                    cout<<t<<"\n";
                }
                // getchar();
                
            }else{
                if(linha.empty()){
                    cout<<"linha vazia\n";
                }else{
                    cout<<"marcador\n";
                    splitToVector(linha, tokens );
                    for(auto t:tokens){
                        tileMatrix.push_back(t);
                    }
                    cout<<"matriz: ";
                    for (auto m: tileMatrix){
                        cout<<m<<" ";
                    }
                // getchar();
                }               

            }
            numberline++;

        }
    mapfile.close();
    }



}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    int area= mapWidth * mapHeight;
    int profundidade = z*area;
    int index = x+ (y*mapWidth) + profundidade;
    return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int width= mapWidth;
    int height = mapHeight;
    //pra cada linha em cada coluna
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            int tileMatrixindex = At(i, j, layer);//onde i é horizontal, j é vertical, e layer é prfundidae
            //renderizar a tile
            int tilex = i* (tileSet->GetTileWidth());
            int tiley = j*(tileSet->GetTileHeight());
            tileSet->RenderTile(tileMatrixindex, tilex, tiley );
        }
    }

}

void TileMap::Render(){
    for(int layer = 0; layer<mapDepth; layer++){
        RenderLayer(layer);
    }


}

int TileMap::GetWidth(){
    return this->mapWidth;
}

int TileMap::GetHeight(){
    return this->mapHeight;
}

int TileMap::GetDepth(){

    return this->mapDepth;
}