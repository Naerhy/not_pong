#ifndef __NOT_PONG_H__
#define __NOT_PONG_H__

#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define sdl_init(a) SDL_Init(a)
#define sdl_quit() SDL_Quit()
#define sdl_create_window(a, b, c, d, e, f) SDL_CreateWindow(a, b, c, d, e, f)
#define sdl_destroy_window(a) SDL_DestroyWindow(a)
#define sdl_create_renderer(a, b, c) SDL_CreateRenderer(a, b, c)
#define sdl_destroy_renderer(a) SDL_DestroyRenderer(a)

typedef SDL_Window sdl_window;
typedef SDL_Renderer sdl_renderer;

typedef struct game_s
{
	sdl_window* window;
	sdl_renderer* renderer;
} game_st;

// init.c
int init_game(game_st* game);

// exit.c
void exit_game(char const* error_msg, game_st* game);

#endif
