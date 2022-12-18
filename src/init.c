#include "not_pong.h"

int init_game(game_st* game)
{
	game->window = NULL;
	game->renderer = NULL;
	if (sdl_init(SDL_INIT_VIDEO))
		return 0;
	game->window = sdl_create_window("not_pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!game->window)
		return 0;
	game->renderer = sdl_create_renderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (!game->renderer)
		return 0;
	return 1;
}
