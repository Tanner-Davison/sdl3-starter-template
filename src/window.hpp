#define SDL_MAIN_HANDLED
#pragma once
#include <SDL2/SDL.h>
#include <string>

class SDLWindow {
 public:
	 SDLWindow(int width, int height, const std::string &title);
	 ~SDLWindow();

	 bool init();                                        // Starts up SDL and creates the window
	 bool loadMedia(const char *path);                   // Loads media
	 void close();                                       // Frees media and shuts down SDL
	 bool handleEvents();                                // Handle SDL events, returns false when window should close
	 bool shouldClose() const { return m_shouldClose; }  // Check if window should close

	 SDL_Window *getWindow() const { return gWindow; }
	 SDL_Renderer *getRenderer() const { return gRenderer; }
	 SDL_Surface *getScreenSurface() const { return gScreenSurface; }

 private:
	 int SCREEN_WIDTH;
	 int SCREEN_HEIGHT;
	 bool m_shouldClose = false;  // Flag to track if window should close

	 SDL_Window *gWindow;          // Destroyed Window;
	 SDL_Surface *gScreenSurface;  // Freed surface;
	 SDL_Surface *gHelloWorld;     // Freed Surface;
	 SDL_Renderer *gRenderer;      // Destroyed Renderer;
};
