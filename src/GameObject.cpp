#include"../include/GameObject.hpp"
#include<iostream>
using namespace::std;

GameObject::GameObject(){
    isDead = false;
    started = false;
}

GameObject::~GameObject() {
    unsigned int sizevector = components.size();
    for(unsigned int i= sizevector; i<0; i--){
        components.erase(components.begin()+i);
    }
    components.clear();
}

void GameObject::Start(){
    	int aux = components.size();
	for(unsigned int i = 0; i < aux; i++) {
		components[i]->Start();
	}

    started = true;
    cout<<"game started";

}
void GameObject::Update(float dt){
    unsigned int sizevector = components.size();
        
    for(unsigned int i = 0; i < sizevector; i++) {
        components[i]->Update(dt);
    
    }

}

void GameObject::Render(){
    unsigned int sizevector = components.size();
        
    for(unsigned int i = 0; i < sizevector; i++) {
        components[i]->Render();
    
    }

}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    cout<<"Adicionando o componente";
    if(started){
        cpt->Start();
    }
    components.emplace_back(cpt);

}

void GameObject::RemoveComponent(Component* cpt){
          unsigned int sizevector = components.size();
          bool found=false;
        
    for(unsigned int i = 0; i < sizevector; i++) {
       if(components[i].get() == cpt){
           found=true;
            components.erase(components.begin()+i);            
       }    
    }
    if(!found){
        cout<<"Componente não foi encontrado\n";
    }

}

Component* GameObject::GetComponent(string type){
    unsigned int sizevector = components.size();


    for(unsigned int i = 0; i < sizevector; i++) {
       if(components[i].get()->Is(type)){
            return components[i].get();        
       }    
    }
    return nullptr;

}
