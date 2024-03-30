#include <SDL2/SDL.h>
#include <stdio.h>

/* Define constants for window dimensions */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* Function to initialize SDL and create a window */
int init_sdl(SDL_Window **window, SDL_Renderer **renderer) {
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    /* Create window */
    *window = SDL_CreateWindow("Raycasting Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    /* Create renderer */
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

/* Function to close SDL and cleanup resources */
void close_sdl(SDL_Window *window, SDL_Renderer *renderer) {
    /* Destroy renderer */
    SDL_DestroyRenderer(renderer);

    /* Destroy window */
    SDL_DestroyWindow(window);

    /* Quit SDL subsystems */
    SDL_Quit();
}

int main() {
    /* SDL variables */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    /* Initialize SDL and create window */
    if (!init_sdl(&window, &renderer)) {
        return 1; /* If initialization fails, exit program */
    }

    /* Main loop */
    int running = 1;
    while (running) {
        /* Event handling */
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = 0; /* Quit if the window is closed */
            }
        }

        /* Clear screen */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        /* Draw code will go here */

        /* Update screen */
        SDL_RenderPresent(renderer);

        /* Add a small delay to control frame rate */
        SDL_Delay(10);
    }

    /* Clean up resources */
    close_sdl(window, renderer);

    return 0;
}

