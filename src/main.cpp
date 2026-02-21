// SDL2 Starter Template

#include "window.hpp"

int main(int argc, char *argv[]) {
	 try {
			SDLWindow gameWindow(800, 600, "My SDL Window");

			// Main game loop
			while (!gameWindow.shouldClose()) {
				 gameWindow.handleEvents();

				 // Clear screen
				 SDL_SetRenderDrawColor(gameWindow.getRenderer(), 0, 0, 0, 255);
				 SDL_RenderClear(gameWindow.getRenderer());

				 // TODO: Render game objects
				 // gameWindow.render();

				 SDL_RenderPresent(gameWindow.getRenderer());
			}
	 } catch (const std::exception &e) {
			printf("Error: %s\n", e.what());
			return -1;
	 }

	 return 0;
}
