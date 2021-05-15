#ifndef _TILESET_H_
#define _TILESET_H_

#include <iostream>
#include "Sprite.hpp"

using std::string;

class TileSet{
    public: 
        TileSet(int TileWidth, int TileHeight, string file);
        void RenderTile(unsigned index, float x, float y);
        int GetTileWidth();
        int GetTileHeight();

    private:
        Sprite *tileSet;
        int rows;
        int columns;
        int tileWidth;
        int tileHeight;


        


};

#endif
