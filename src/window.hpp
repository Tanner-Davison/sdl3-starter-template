#define SDL_MAIN_HANDLED
#pragma once
#include <SDL2/SDL.h>
#include <string>

class SDLWindow {
 public:
	 SDLWindow(int width, int height, const std::string &title);
	 ~SDLWindow();

	 bool init();                                        // Starts up SDL and creates the window
	 void close();                                       // Frees media and shuts down SDL
	 bool handleEvents();                                // Handle SDL events, returns false when window should close
	 bool shouldClose() const { return m_shouldClose; }  // Check if window should close

	 SDL_Window *getWindow() const { return gWindow; }
	 SDL_Renderer *getRenderer() const { return gRenderer; }
	 SDL_Surface *getScreenSurface() const { return gScreenSurface; }

 private:
	 int SCREEN_WIDTH;
	 int SCREEN_HEIGHT;
	 std::string m_title;
	 bool m_shouldClose = false;  // Flag to track if window should close

	 SDL_Window *gWindow;          // Destroyed in close()
	 SDL_Surface *gScreenSurface;  // Freed in close()
	 SDL_Renderer *gRenderer;      // Destroyed in close()
};
