#ifndef _GAMEO_H_
#define _GAMEO_H_

#include <string>
#include <vector>
#include <memory>
#include<iostream>
#include"Component.hpp"
#include"Rect.hpp"

using std::string;
using std::vector;


class Component;

class GameObject{
    public: 
        GameObject();
        ~GameObject();
        void Start();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(string type);
        Rect box;
        bool started;

    private:
        vector<std::shared_ptr<Component>> components;
        bool isDead;

};

#endif
