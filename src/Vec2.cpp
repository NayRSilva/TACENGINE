#include"../include/Vec2.hpp"
#include <cmath>

Vec2 Vec2::operator+(Vec2 b){
    Vec2 auxreturn;
    auxreturn.x = ((this->x)+(b.x));
    auxreturn.y = ((this->y)+(b.y));

    return auxreturn;

}

Vec2 Vec2::operator-(Vec2 b){
    Vec2 auxreturn;
    auxreturn.x = ((this->x)-(b.x));
    auxreturn.y = ((this->y)-(b.y));

    return auxreturn;
}


Vec2 Vec2::MultEscalar(Vec2 a, float escalar){
    Vec2 auxreturn;
    auxreturn.x= ((a.x)*(escalar));
    auxreturn.y= ((a.y)*(escalar));

    return auxreturn;

}

Vec2 Vec2::Rotate(float angle){
    Vec2 aux;
    aux.x= (x * cos(angle)) - (y * sin(angle));
    aux.y= (y * cos(angle)) + (x * sin(angle));
    return aux;
}

float Vec2::GetHipo(Vec2 newpos, Vec2 oldpos){
    float newx = newpos.x;
    float oldx = oldpos.x;

    float sizeX = newx - oldx;

    float newy = newpos.y;
    float oldy = oldpos.y;

    float sizeY = newy - oldy;

    float hipo = sqrt(pow(sizeX, 2) + pow(sizeY, 2));

    return hipo;
   

}


Vec2 Vec2::Normalize(Vec2 vec, Vec2 othervec){

    Vec2 aux = vec-othervec;
    float square = sqrt(pow(aux.x, 2)+pow(aux.y,2));
    aux.x = aux.x/square;
    aux.y = aux.y/square;

    return aux;

}
