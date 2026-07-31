#include "Application.h"
#include <stdexcept>
#include "MorseInput.h"
#include "MorseTranslator.h"
#include <iostream>


Application::Application(){
    Init();
    m_Window = new Window();
    m_Renderer = new Renderer(m_Window->m_Handle);
    m_Running=true;
}

Application::~Application(){
    delete m_Renderer;
    delete m_Window;
    TTF_Quit();
    SDL_Quit();
}

void Application::Init(){
    int status = SDL_Init(SDL_INIT_VIDEO);
    if(status!=0){
        throw std::runtime_error(SDL_GetError());
    }
    int tffStatus = TTF_Init();
    if(tffStatus!=0){
        throw std::runtime_error(TTF_GetError());
    }
}

void Application::Run(){


    while(m_Running){
        
        SDL_Event event;
        while(SDL_PollEvent(&event)){

            switch (event.type)
            {
            case SDL_QUIT:
                m_Running = false;
                break;
            
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_r){
                    m_MorseCode.clear();
                    m_Text.clear();
                }
                else{
                     m_MorseInput.HandleEvent(event);
                }
                break;
            

            case SDL_KEYUP:
                m_MorseInput.HandleEvent(event);
                break;

            default:
                break;
            }    

        }   
        
        std::optional<char> lastSymbol = m_MorseInput.GetSymbol();
        if(lastSymbol!=std::nullopt){
            m_MorseCode+=lastSymbol.value();
            m_LastSymbolTime = SDL_GetTicks();
        }
        
        if(!m_MorseCode.empty() &&  SDL_GetTicks() - m_LastSymbolTime >= 2000){
            auto letter = MorseTranslator::DecodeLetter(m_MorseCode);
            if(letter)
            {
                m_Text+=letter.value();
            }
            m_MorseCode.clear();
        }

        m_Renderer->Clear();

        SDL_Color white = {255,255,255,255};
        std::string morseDisplay = "Morse: " + m_MorseCode;
        std::string textDisplay = "Text: " + m_Text;

        m_Renderer->DrawText(morseDisplay.c_str(), white, 450, 360);
        m_Renderer->DrawText(textDisplay.c_str(), white, 0, 0);

        m_Renderer->Present();

    }

}
