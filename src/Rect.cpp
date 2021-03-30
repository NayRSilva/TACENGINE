#include"../include/Rect.hpp"


bool Rect::Contains(float mouseX, float mouseY){
    float currentXWidth= x+w;//a largura vai do ponto x até o final da largura
    float currentYHeight= y+h;//a altura vai do ponto y ao final da altura
    bool containX=false;
    bool containY=false;

    if((mouseX>=x) && (mouseX<=currentXWidth)){
        //X é a menor posição, porque qualquer coisa antes de x está fora
        //se for maior que a largura na posição X, então é falso, tem que ser menor
        containX=true;
    }
    if((mouseY>=y)&&(mouseY<=currentYHeight)){//Idem ao de cima
        containY=true;

    }

    if((containX)&&(containY)){
        return true;
    }

    return false;

}