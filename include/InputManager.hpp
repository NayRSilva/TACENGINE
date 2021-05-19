#ifndef _INPUT_hpp
#define _INPUT_hpp

#include <unordered_map>

#define LEFT_ARROW SDLK_LEFT
#define RIGHT_ARROW SDLK_RIGHT
#define UP_ARROW SDLK_UP
#define DOWN_ARROW SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager {
    public:
    
        void Update();

        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool IsKeyDown(int key);

        bool MousePress(int button);
        bool MouseRelease(int button);
        bool IsMouseDown(int button);

        int GetMouseX();
        int GetMouseY();

        bool QuitRequested();

        static InputManager& GetInstance();
    private:
        InputManager();
        ~InputManager();

        bool mouseState[6];
        int mouseUpdate[6];

        std::unordered_map<int, bool> keyState;
        std::unordered_map<int, int> keyUpdate;

        bool quitRequested;

        int updateCounter;

        int mouseX;
        int mouseY;
};

#endif