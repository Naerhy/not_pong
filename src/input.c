#include "not_pong.h"

void handle_keys_down(sdl_event* events, entity_st* player)
{
	if (!events->key.repeat)
	{
		if (events->key.keysym.scancode == SDL_SCANCODE_UP)
			player->dy--;
		if (events->key.keysym.scancode == SDL_SCANCODE_DOWN)
			player->dy++;
	}
}

void handle_keys_up(sdl_event* events, entity_st* player)
{
	if (!events->key.repeat)
	{
		if (events->key.keysym.scancode == SDL_SCANCODE_UP)
			player->dy++;
		if (events->key.keysym.scancode == SDL_SCANCODE_DOWN)
			player->dy--;
	}
}
