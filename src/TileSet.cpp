
#include "../include/TileSet.hpp"
#include <iostream>


using std::string;
using std::cout;


TileSet::TileSet(int tileWidth, int tileHeight, string file) : tileWidth(tileWidth), tileHeight(tileHeight){

	GameObject *go= new GameObject();

	tileSet = new Sprite(*go, file);
    if(tileSet!=nullptr){//se conseguir abrir o sprite
        // cout<<"abrimos o sprite do tileset\n";
        columns = ((tileSet->GetWidth())/tileWidth);
        rows = ((tileSet->GetHeight())/tileHeight);
        // cout<<"columns: "<<columns<<"\n rows:"<<rows<<"\n";

    }


}

void TileSet::RenderTile(unsigned index, float x, float y){
    int numberTiles = columns*rows;
    if((index>=0)&&(index<numberTiles)){
        //o SetClip precisa de um x e um y
        /*the x location of the rectangle's upper left corner
        the y location of the rectangle's upper left corner */

        //calculo do x: modulo do indice pela quantidade de colunas pois
        /* |  |  |  | | |
            eu tenho 5 colunas
            se minha coluna é 2, o primeiro x é 0, o index 1 é 0+tileswidth e o index 2 é 0+2*tileswidht
            se meu index é 7, o x deve estar no mesmo lugar que o 2 pois vai ate o final da 5 e volta ao inicio. 7%5 = 2
        
        //calculo do y: 
          |__|__|__|__|
          |__|__|__|__|
        descobrir em qual row esta minha posicao
        se for menor que 5, esta em 0
        se for de 5 a 10 esta em 1.
        dividir indice/coluna  
        multiplicar pela altura da tile       
            
        
         */
        int leftx= (index%columns)* tileWidth;
        int lefty= (index/columns)*tileHeight;
        tileSet->SetClip(leftx,lefty, tileWidth, tileHeight);
        tileSet->Render(x, y);



    }
}

int TileSet::GetTileHeight(){
    return tileHeight;
}
int TileSet::GetTileWidth(){
    return tileWidth;
}