#ifndef __NOT_PONG_H__
#define __NOT_PONG_H__

#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MARGIN 10

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
#define sdl_create_texture(a, b, c, d, e) SDL_CreateTexture(a, b, c, d, e)
#define sdl_destroy_texture(a) SDL_DestroyTexture(a)
#define sdl_render_copy(a, b, c, d) SDL_RenderCopy(a, b, c, d)
#define sdl_set_render_target(a, b) SDL_SetRenderTarget(a, b)
#define sdl_render_fill_rect(a, b) SDL_RenderFillRect(a, b)
#define sdl_get_ticks() SDL_GetTicks()

typedef SDL_Window sdl_window;
typedef SDL_Renderer sdl_renderer;
typedef SDL_Event sdl_event;
typedef SDL_Texture sdl_texture;
typedef SDL_Rect sdl_rect;

typedef struct player_s
{
	int width;
	int height;
	int speed;
	int direction;
	float x;
	float y;
} player_st;

typedef struct game_s
{
	sdl_window* window;
	sdl_renderer* renderer;
	sdl_event events;
	sdl_texture* bg_tex;
	sdl_rect bg_tex_rect;
	player_st player_1;
} game_st;

// draw.c
void draw_background(game_st* game);
void draw_players(game_st* game);

// exit.c
void exit_game(char const* error_msg, game_st* game);

// init.c
int init_game(game_st* game);
void init_player(game_st* game);
void create_background_texture(game_st* game);
sdl_rect create_rectangle(int x, int y, int w, int h);

// input.c
void handle_keys_down(game_st* game);
void handle_keys_up(game_st* game);

// update.c
void update_player_pos(game_st* game, float delta);

#endif
