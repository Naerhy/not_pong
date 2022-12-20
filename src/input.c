#include "not_pong.h"

void handle_keys_down(game_st* game)
{
	if (!game->events.key.repeat)
	{
		if (game->events.key.keysym.scancode == SDL_SCANCODE_UP)
			game->player_1_direction--;
		if (game->events.key.keysym.scancode == SDL_SCANCODE_DOWN)
			game->player_1_direction++;
	}
}

void handle_keys_up(game_st* game)
{
	if (!game->events.key.repeat)
	{
		if (game->events.key.keysym.scancode == SDL_SCANCODE_UP)
			game->player_1_direction++;
		if (game->events.key.keysym.scancode == SDL_SCANCODE_DOWN)
			game->player_1_direction--;
	}
}
