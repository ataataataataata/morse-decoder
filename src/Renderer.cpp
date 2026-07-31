#include "Renderer.h"
#include <stdexcept>

Renderer::Renderer(SDL_Window* window){
    m_Handle = SDL_CreateRenderer(window,-1,0);
    if(m_Handle==nullptr){
        throw std::runtime_error(SDL_GetError());
    }
    m_Font = TTF_OpenFont("assets/fonts/DejaVuSans.ttf", 64);
    if(m_Font==nullptr){
        throw std::runtime_error(TTF_GetError());
    }
}

Renderer::~Renderer(){
    if(m_Handle!=nullptr){
        SDL_DestroyRenderer(m_Handle);
    }
    if(m_Font!=nullptr){
        TTF_CloseFont(m_Font);
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

void Renderer::DrawText(const char* text, SDL_Color fg, int x, int y){
    SDL_Surface* surface = TTF_RenderText_Blended(m_Font,text,fg);
    if(surface==nullptr){
        throw std::runtime_error(TTF_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Handle,surface);
    if(texture==nullptr){
        SDL_FreeSurface(surface);
        throw std::runtime_error(SDL_GetError());
    }

    int w;
    int h;

    SDL_QueryTexture(texture,nullptr,nullptr,&w,&h);
    
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    int renderCopyStatus = SDL_RenderCopy(m_Handle,texture,nullptr,&rect);
    if(renderCopyStatus!=0){
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
        throw std::runtime_error(SDL_GetError());
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}