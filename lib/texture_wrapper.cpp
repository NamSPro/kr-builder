// texture_wrapper.cpp
// This file implements functions declared in texture_wrapper.h

#include <cstdio>
#include "texture_wrapper.h"

WTexture::WTexture(){
	// initialize variables
	mTexture = nullptr;
	mWidth = mHeight = 0;
	return;
}

WTexture::~WTexture(){
	free();
	return;
}

bool WTexture::loadFromFile(std::string path, SDL_Renderer* renderer){
	// get rid of preexisting texture
	free();

	// final texture
	SDL_Texture* newTexture = nullptr;

	// load surface
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == nullptr){
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}

	// color key if needed
	SDL_SetColorKey(loadedSurface, SDL_FALSE, 0);
	// create texture from surface
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if(newTexture == nullptr){
		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else{
		mWidth = loadedSurface->w;
		mHeight = loadedSurface->h;
	}
	SDL_FreeSurface(loadedSurface);

	// return
	mTexture = newTexture;
	return mTexture != nullptr;
}

void WTexture::render(int x, int y, SDL_Renderer* renderer, SDL_Rect* targetQuad){
	// set rendering space and render
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	SDL_RenderCopy(renderer, mTexture, targetQuad, &renderQuad);
	return;
}

void WTexture::renderEx(int x, int y, SDL_Renderer* renderer, SDL_Rect* targetQuad, double angle, SDL_Point* center, SDL_RendererFlip flip){
	// basically render, but with rotation and flipping
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	SDL_RenderCopyEx(renderer, mTexture, targetQuad, &renderQuad, angle, center, flip);
	return;
}

void WTexture::free(){
	// free the texture and reset variables, if it exists
	if(mTexture == nullptr) return;
	mTexture = nullptr;
	mWidth = mHeight = 0;
	return;
}

int WTexture::getWidth(){
	return mWidth;
}

int WTexture::getHeight(){
	return mHeight;
}