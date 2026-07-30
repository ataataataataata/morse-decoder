#include "Renderer.h"
#include <stdexcept>

Renderer::Renderer(SDL_Window* window){
    m_Handle = SDL_CreateRenderer(window,-1,0);
    if(m_Handle==nullptr){
        throw std::runtime_error(SDL_GetError());
    }
}

Renderer::~Renderer(){
    if(m_Handle!=nullptr){
        SDL_DestroyRenderer(m_Handle);
    }
}

void Renderer::Clear(){
    int status = SDL_RenderClear(m_Handle);
    if(status!=0){
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::Present(){
    SDL_RenderPresent(m_Handle);
}

void Renderer::SetDrawColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a){
    int status = SDL_SetRenderDrawColor(m_Handle,r,g,b,a);
    if(status!=0){
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::DrawRect(SDL_Rect* rect){
    int status = SDL_RenderDrawRect(m_Handle,rect);
    if(status!=0){
        throw std::runtime_error(SDL_GetError());
    }
}

void Renderer::DrawLine(int x1,int y1,int x2,int y2){
    int status = SDL_RenderDrawLine(m_Handle,x1,y1,x2,y2);
    if(status!=0){
        throw std::runtime_error(SDL_GetError());
    }
}