#include <iostream>
#include <ctime>

#include <SDL.h>
#include <SDL_image.h>
#include "pugixml.hpp"

#include "Engine.h"

typedef struct config
{
	bool fullscreen;
	unsigned int wWindowSize;
	unsigned int hWindowSize;
	long seed;
} config;

config loadConfiguration(std::string configFile)
{
	pugi::xml_document settings;
	config configuration;
	pugi::xml_parse_result result = settings.load_file(configFile.c_str());
	if (result)
	{
		// configuration.fullscreen = settings.child("settings").child("fullscreen").value()!="";
	}
	else
	{
		// std::cout << "Error while loading settings : using default settings" << std::endl;
	}
	configuration.fullscreen = false;
	configuration.wWindowSize = 800;
	configuration.hWindowSize = 600;
	configuration.seed = 0;

	return configuration;
}

bool init(SDL_Window** window, SDL_Renderer ** renderer, config configuration)
{
	//Initialization flag
	bool success = true;
	if (configuration.seed == 0)
	{
		srand(time(NULL));
	}
	else
	{
		srand(configuration.seed);
	}
	
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::string error = "SDL could not initialize! SDL Error : ";
		throw error + SDL_GetError();
	}
	
	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	}

	// window creation
	*window = SDL_CreateWindow("The Dreamers Realm", 
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, 
								configuration.wWindowSize, 
								configuration.hWindowSize,
								SDL_WINDOW_SHOWN);
	if (*window == NULL)
	{
		std::string error = "Window could not be created! SDL Error:";
		throw error + SDL_GetError();
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::string error = "renderer could not be created! SDL Error:";
		throw error + SDL_GetError();
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::string error = "SDL_image could not initialize! SDL_image Error: ";
		throw error + IMG_GetError();
	}

	return true;
}


int main(int argc, char* args[])
{
	config configuration = loadConfiguration("xml/settings.xml");
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;

	// initialization
	try
	{
		init(&window, &renderer, configuration);
	}
	catch (std::string const& error)
	{
		std::cout << error << std::endl;
		return 0;
	}
	Engine * engine = new Engine(window,renderer);
	engine->init();
	engine->mainLoop();
	return 0;
}