#include <iostream>
#include <cstdio>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "lib/calculator/includer.h"
#include "lib/texture_wrapper.h"
#include "lib/tests/tests.h"

const int SCREEN_WIDTH = 1280;
const int HALF_SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 720;

const int TILE_SIZE = 70;

bool init();

bool loadMedia();

void close();

// load individual image
SDL_Texture* loadTexture(std::string path);

// the window we're rendering
SDL_Window* gWindow = nullptr;
// the renderer
SDL_Renderer* gRenderer = nullptr;
WTexture gBorders[BORDER_TOTAL];
WTexture gBgTile;

TTF_Font* gFont = nullptr;

bool init(){
	// init flag
	bool success = true;

	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Failed to initialize SDL! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else{
		//Create window
		gWindow = SDL_CreateWindow("King's Raid Hero Builder", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == nullptr){
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer == nullptr){
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_NONE);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)){
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if(TTF_Init() != 0){
					printf("SDL_ttf could not initialize! SDL_ttf error: %s\n", TTF_GetError());
					success = false;
				}
				else{
					// initialize TTF loading
					gFont = TTF_OpenFont("NanumGothicExtraBold.ttf", 20);
					if(gFont == nullptr){
						printf("SDL_ttf failed to open! SDL_ttf error: %s\n", TTF_GetError());
						success = false;
					}
				}
			}
		}
	}
	return success;
}

bool loadMedia(){
    //Loading success flag
	bool success = true;

	//Load PNG texture
	if(!gBorders[LR_BORDER].loadFromFile("img/leftright-border.png", gRenderer)){
		printf("Failed to load left-right border texture image!\n");
		success = false;
	}
	if(!gBorders[TOP_BORDER].loadFromFile("img/top-border.png", gRenderer)){
		printf("Failed to load top border texture image!\n");
		success = false;
	}
	if(!gBgTile.loadFromFile("img/tiles.png", gRenderer)){
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void close(){
	// destroy texture
	for(int i = 0; i < BORDER_TOTAL; i++){
		gBorders[i].free();
	}
	gBgTile.free();

	// destroy resources
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	// quit systems
	IMG_Quit();
	SDL_Quit();
	return;
}

SDL_Texture* loadTexture(std::string path){
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL){
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if(newTexture == nullptr){
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main(int argc, char* argv[]){
	// start up SDL and create window
	if(!init()){
		std::cout << "Failed to initialize!\n";
		return -1;
	}
	// load media
	if(!loadMedia()){
		std::cout << "Failed to load media!\n";
		return -1;
	}

	// loop flag
	bool quit = false;
	// event handler
	SDL_Event e;

	while(!quit){
		// input
		while(SDL_PollEvent(&e) != 0){
			// user requests exit
			if(e.type == SDL_QUIT){
				quit = true;
			}
		}
		// logic
		// render
		SDL_RenderClear(gRenderer);
		// render texture to screen
		// background tiles
		for(int i = 0; i <= SCREEN_WIDTH / TILE_SIZE; i++){
			for(int j = 0; j <= SCREEN_HEIGHT / TILE_SIZE; j++){
				gBgTile.render(TILE_SIZE * i, TILE_SIZE * j, gRenderer);
			}
		}
		gBorders[LR_BORDER].render(0, 0, gRenderer);
		gBorders[LR_BORDER].renderEx(SCREEN_WIDTH - gBorders[LR_BORDER].getWidth(), 0,  gRenderer, nullptr, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
		gBorders[TOP_BORDER].render(0, 0, gRenderer);

		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	// free resources and close SDL
	close();
	test();
	return 0;
}
