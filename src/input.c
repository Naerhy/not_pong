#include "not_pong.h"

void handle_keys_down(sdl_event* events, entity_st* player1, entity_st* player2)
{
	if (!events->key.repeat)
	{
		if (events->key.keysym.scancode == SDL_SCANCODE_W)
			player1->dy--;
		if (events->key.keysym.scancode == SDL_SCANCODE_S)
			player1->dy++;
		if (events->key.keysym.scancode == SDL_SCANCODE_O)
			player2->dy--;
		if (events->key.keysym.scancode == SDL_SCANCODE_L)
			player2->dy++;
	}
}

void handle_keys_up(sdl_event* events, entity_st* player1, entity_st* player2)
{
	if (!events->key.repeat)
	{
		if (events->key.keysym.scancode == SDL_SCANCODE_W)
			player1->dy++;
		if (events->key.keysym.scancode == SDL_SCANCODE_S)
			player1->dy--;
		if (events->key.keysym.scancode == SDL_SCANCODE_O)
			player2->dy++;
		if (events->key.keysym.scancode == SDL_SCANCODE_L)
			player2->dy--;
	}
}
