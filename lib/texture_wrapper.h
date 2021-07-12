// texture_wrapper.h
// This file declares the class WTexture (Wrapper on Texture), a wrapper on SDL_Texture

#include <string>
#include <SDL.h>
#include <SDL_image.h>

// this is in essence a wrapper on the SDL_Texture, with w/h properties, load/render functions
class WTexture{
public:
    // initializes variables
    WTexture();
    // deallocates memory
    ~WTexture();
    // loads image from path
    bool loadFromFile(std::string path, SDL_Renderer* renderer);
    // render at the given point
    void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* targetQuad = nullptr);
    void renderEx(int x, int y, SDL_Renderer* renderer, SDL_Rect* targetQuad = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
    // deallocates texture without destroying the wrapper
    void free();

    // get image dimensions
    int getWidth();
    int getHeight();

private:
    // the actual texture
    SDL_Texture* mTexture;
    // image dimensions
    int mWidth, mHeight;
};