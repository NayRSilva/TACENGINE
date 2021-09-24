#ifndef _ALIEN_H_
#define _ALIEN_H_

#include"Component.hpp"
#include"Vec2.hpp"
#include <queue>
using std::string;
using std::queue;



class Alien : public Component{
    public:
        Alien(GameObject &associated, int nMinions);
        ~Alien();
        void Start();
        void Update(float dt);
        void Render();
        bool Is(string type);

    private:
        class Action{
            public:
            enum ActionType {MOVE, SHOOT};
            ActionType type;
            Action(ActionType type, float x, float y);
            Vec2 pos;
        };
        Vec2 speed;
        int hp;
        queue<Action> taskQueue;
        std::vector<std::weak_ptr<GameObject>> minionArray;




};

#endif
