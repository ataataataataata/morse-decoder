#pragma once
#include <SDL2/SDL.h>
#include "Window.h"
#include "Renderer.h"
#include <string>
#include "MorseInput.h"

class Application{
    public:
        
        Application();
        ~Application();
        void Run();
    
    private:
        void Init();
        Window* m_Window;
        Renderer* m_Renderer;
        MorseInput m_MorseInput;
        std::string m_MorseCode ="";
        Uint32 m_LastSymbolTime = 0;
        bool m_Running = false;
};
