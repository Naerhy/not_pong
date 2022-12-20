#include "not_pong.h"

void update_player_pos(game_st* game, float delta)
{
	if (game->player_1.direction == 1)
		game->player_1.y += game->player_1.speed * delta;
	if (game->player_1.direction == -1)
		game->player_1.y -= game->player_1.speed * delta;
}
