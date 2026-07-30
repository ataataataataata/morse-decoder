#include "MorseInput.h"

void MorseInput::HandleEvent(SDL_Event& event){
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_SPACE && event.key.repeat == 0){
            m_IsPressed=true;
            m_PressedStartTime = SDL_GetTicks();
        }
    }
    
    if(event.type == SDL_KEYUP){
        if(event.key.keysym.sym == SDLK_SPACE && m_IsPressed==true){
            Uint32 duration = SDL_GetTicks()-m_PressedStartTime;
            if(duration>=100 && duration<400){
                m_LastSymbol = '.';
            }
            else if(duration>=400 && duration<900){
                m_LastSymbol = '-';
            }
            else{
                m_LastSymbol = std::nullopt;
            }
            m_IsPressed=false;
        }
    }
}

std::optional<char> MorseInput::GetSymbol(){
    std::optional<char> lastSymbol = m_LastSymbol;
    m_LastSymbol = std::nullopt;
    return lastSymbol;
}