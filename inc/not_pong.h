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
#define sdl_poll_event(a) SDL_PollEvent(a)
#define sdl_set_render_draw_color(a, b, c, d, e) SDL_SetRenderDrawColor(a, b, c, d, e)
#define sdl_render_clear(a) SDL_RenderClear(a)
#define sdl_render_present(a) SDL_RenderPresent(a)

typedef SDL_Window sdl_window;
typedef SDL_Renderer sdl_renderer;
typedef SDL_Event sdl_event;

typedef struct game_s
{
	sdl_window* window;
	sdl_renderer* renderer;
	sdl_event events;
} game_st;

// init.c
int init_game(game_st* game);

// exit.c
void exit_game(char const* error_msg, game_st* game);

#endif
