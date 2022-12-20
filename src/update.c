#include "not_pong.h"

void update_player_pos(game_st* game, float delta)
{
	float previous_pos_y;

	previous_pos_y = game->player_1.y;
	if (game->player_1.dy)
		game->player_1.y += game->player_1.dy * (game->player_1.speed * delta);

	if (game->player_1.y < MARGIN
			|| game->player_1.y > WINDOW_HEIGHT - MARGIN - game->player_1.height)
		game->player_1.y = previous_pos_y;
}
