#pragma once
#include <SDL2/SDL.h>

class Window {
    public:
        Window();
        ~Window();

        SDL_Window* m_Handle = nullptr;
            
};