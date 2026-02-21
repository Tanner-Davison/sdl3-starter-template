#include "window.hpp"
#include <stdexcept>

SDLWindow::SDLWindow(int width, int height, const std::string &title)
    : gWindow(nullptr), gScreenSurface(nullptr), gRenderer(nullptr) {
	 SCREEN_WIDTH  = width;
	 SCREEN_HEIGHT = height;
	 m_title       = title;
	 if (!init()) {
			throw std::runtime_error("Failed to initialize SDL window.");
	 }
}

SDLWindow::~SDLWindow() { close(); }

bool SDLWindow::init() {
	 // Initialize SDL video subsystem
	 if (!SDL_Init(SDL_INIT_VIDEO)) {
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Create the main window
	 gWindow = SDL_CreateWindow(m_title.c_str(), SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	 if (gWindow == nullptr) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Create hardware-accelerated renderer
	 gRenderer = SDL_CreateRenderer(gWindow, NULL);
	 if (gRenderer == nullptr) {
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
	 }

	 // Get the window's surface
	 gScreenSurface = SDL_GetWindowSurface(gWindow);
	 return true;
}

bool SDLWindow::handleEvents() {
	 SDL_Event e;

	 while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				 m_shouldClose = true;
				 return false;
			}
	 }
	 return true;
}

void SDLWindow::close() {
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

	 // Destroy the screen surface
	 if (gScreenSurface != nullptr) {
			SDL_DestroySurface(gScreenSurface);
			gScreenSurface = nullptr;
	 }

	 SDL_Quit();
}
