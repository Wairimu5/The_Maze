#ifndef HEADER_H
#define HEADER_H

#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>

/* Constants */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TEX_COUNT 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/* Structures */
typedef struct {
    double x;
    double y;
} point_t;

/* Global Variables */
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
extern uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
extern point_t pos;
extern point_t dir;
extern point_t plane;
extern double time;

/* Functions */
int *parseMap(char *filename, int *map);
void loadTextures(char *mapName);

bool initSDL(void);
void updateRenderer(bool textured);
void closeSDL(void);

void input(int *maze);
bool quit(void);

void raycaster(int *maze, bool textured);
void renderWalls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir, double distToWall, int x, int side, bool textured);
void renderBGFlat(void);
void renderBGTex(SDL_Point map, point_t rayDir, double distToWall, double wallX, int drawEnd, int x, int side);

#endif /* HEADER_H */

