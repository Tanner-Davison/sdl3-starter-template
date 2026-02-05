#include "window.hpp"
#include "SDL_video.h"
#include <stdexcept>

SDLWindow::SDLWindow(int width, int height, const std::string &title)
    : gWindow(nullptr), gScreenSurface(nullptr), gHelloWorld(nullptr), gRenderer(nullptr) {
	 SCREEN_WIDTH  = width;
	 SCREEN_HEIGHT = height;
	 if (!init()) {
			throw std::runtime_error("Failed to initialize SDL window.");
	 }
}

SDLWindow::~SDLWindow() { close(); }

bool SDLWindow::init() {
	 // Initialize SDL video subsystem
	 if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Create the main window
	 gWindow = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	 if (gWindow == nullptr) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Create hardware-accelerated renderer
	 gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	 if (gRenderer == nullptr) {
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Get the window's surface
	 gScreenSurface = SDL_GetWindowSurface(gWindow);
	 return true;
}

bool SDLWindow::loadMedia(const char *path) {  // UNUSED
	 // Load BMP image
	 gHelloWorld = SDL_LoadBMP(path);
	 if (gHelloWorld == nullptr) {
			printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
			return false;
	 }
	 return true;
}

bool SDLWindow::handleEvents() {
	 SDL_Event e;

	 while (SDL_PollEvent(&e)) {
			// Check for quit event
			if (e.type == SDL_QUIT) {
				 m_shouldClose = true;
				 return false;
			}
	 }
	 return true;
}

void SDLWindow::close() {
	 // Free the loaded image surface
	 if (gHelloWorld != nullptr) {
			SDL_FreeSurface(gHelloWorld);
			gHelloWorld = nullptr;
	 }

	 // Destroy the renderer
	 if (gRenderer != nullptr) {
			SDL_DestroyRenderer(gRenderer);
			gRenderer = nullptr;
	 }

	 // Destroy the window
	 if (gWindow != nullptr) {
			SDL_DestroyWindow(gWindow);
			gWindow = nullptr;
	 }

	 // Free the screen surface
	 if (gScreenSurface != nullptr) {
			SDL_FreeSurface(gScreenSurface);
			gScreenSurface = nullptr;
	 }

	 // Shut down SDL
	 SDL_Quit();
}
