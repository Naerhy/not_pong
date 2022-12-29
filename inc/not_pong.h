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

typedef enum entity_type_e
{
	BALL,
	PLAYER1,
	PLAYER2
} entity_type_et;

typedef struct entity_s
{
	int width;
	int height;
	int speed;
	float x;
	float y;
	float dx;
	float dy;
	sdl_rect rect;
} entity_st;

typedef struct game_s
{
	sdl_window* window;
	sdl_renderer* renderer;
	sdl_event events;
	sdl_texture* bg_tex;
	sdl_rect bg_tex_rect;
	entity_st player1;
	entity_st player2;
	entity_st ball;
} game_st;

// draw.c
void draw_frame(game_st* game);

// exit.c
void exit_game(char const* error_msg, game_st* game);

// init.c
int init_game(game_st* game);
entity_st create_entity(entity_type_et name);
void create_background_texture(game_st* game);
sdl_rect create_rectangle(int x, int y, int w, int h);

// input.c
void handle_keys_down(sdl_event* events, entity_st* player1, entity_st* player2);
void handle_keys_up(sdl_event* events, entity_st* player1, entity_st* player2);

// update.c
void update_entities(entity_st* player1, entity_st* player2, entity_st* ball, float delta);
void update_player(entity_st* player, float delta);
void update_ball(entity_st* ball, entity_st* player, entity_st* opponent, float delta);

#endif
