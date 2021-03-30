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

Vec2 Vec2::GetRotated(float angle){
    Vec2 aux;
    aux.x= (x * cos(angle)) - (y * sin(angle));
    aux.y= (y * cos(angle)) + (x * sin(angle));

}
