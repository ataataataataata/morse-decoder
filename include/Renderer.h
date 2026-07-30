#pragma once
#include <SDL2/SDL.h>

class Renderer{
    public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void Clear();
    void Present();
    void SetDrawColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a);
    
    /*typedef struct SDL_Rect
    {
    int x, y;
    int w, h;
    } SDL_Rect;*/
    void DrawRect(SDL_Rect* rect); 
    void DrawLine(int x1,int y1,int x2,int y2);

    SDL_Renderer* m_Handle = nullptr;

};