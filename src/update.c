#include "not_pong.h"

void update_player_pos(game_st* game)
{
	if (game->player_1_direction == 1)
		game->player_1.y += game->player_speed;
	if (game->player_1_direction == -1)
		game->player_1.y -= game->player_speed;
}
