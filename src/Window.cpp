#include "Window.h"
#include <stdexcept>

Window::Window(){
    
    m_Handle = SDL_CreateWindow(
        "Morse",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1200,
        720,
        SDL_WINDOW_SHOWN
    );
    
    if(m_Handle==nullptr){
        throw std::runtime_error(SDL_GetError());
    }

}

Window::~Window(){
    if(m_Handle!=nullptr){
        SDL_DestroyWindow(m_Handle);
        m_Handle=nullptr;
    }
}