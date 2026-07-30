#pragma once
#include <SDL2/SDL.h>
#include <optional>


class MorseInput{
    public:
        void HandleEvent(SDL_Event& event);
        std::optional<char> GetSymbol();
    
    private:
        bool m_IsPressed = false;
        Uint32 m_PressedStartTime = 0;
        std::optional<char> m_LastSymbol;
};