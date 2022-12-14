#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "Commons.h"
#include "constants.h"
#include "ScreenManager.h"
using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
Uint32 g_time;
ScreenManager* screen_manager;



void Render()
{
	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(g_renderer);

	screen_manager->Render();

	//Update the screen
	SDL_RenderPresent(g_renderer);
}

bool InitSDL()
{

	//initialise the mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "Mixer could not init. Error: " << Mix_GetError();
		return false;
	}

	if (TTF_Init() < 0)
	{
		cout << "TTF could not init. Error: " << TTF_GetError();
		return false;
	}


	//setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		//else, then window is created
		g_window = SDL_CreateWindow("Pacman",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		//did the window get created?
		if (g_window == nullptr)
		{
			//window failed
			cout << "window was not created. error " << SDL_GetError();
			return false;
		}
	}

	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

	if (g_renderer != nullptr)
	{
		//init PNG loading
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
			return false;
		}
	}
	else
	{
		cout << "Renderer could not initialise. Error: " << SDL_GetError();
		return false;
	}

	return true;
}



void CloseSDL()
{
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

	g_renderer = nullptr;
	SDL_DestroyRenderer(g_renderer);


	delete screen_manager;
	screen_manager = nullptr;
}


bool Update()
{
	Uint32 new_time = SDL_GetTicks();

	//Event handler
	SDL_Event e;

	//get events
	SDL_PollEvent(&e);

	//if x is pressed the window closes
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_x: {
			return true;
			break; }
		}
	}

screen_manager->Update((float)(new_time - g_time) / 1000.0f, e);
	g_time = new_time;
	return false;
}



int main(int argc, char* args[]) 
{
	//check if sdl was setup correctly
	if (InitSDL())
	{
		screen_manager = new ScreenManager(g_renderer, SCREEN_MENU);

		//set the time
		g_time = SDL_GetTicks();

		bool quit = false;

			while (!quit)
			{
				Render();
				quit = Update();
			}
	}

	CloseSDL();

	return 0;
}
