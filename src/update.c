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

static int check_collision(entity_st* ent_1, entity_st* ent_2)
{
	if (ent_1->x < ent_2->x + ent_2->width && ent_1->x + ent_1->width > ent_2->x
			&& ent_1->y < ent_2->y + ent_2->height && ent_1->y + ent_1->height > ent_2->y)
		return 1;
	return 0;
}

void update_ball_pos(game_st* game, float delta)
{
	float previous_pos_x;
	float previous_pos_y;

	previous_pos_x = game->ball.x;
	previous_pos_y = game->ball.y;
	game->ball.x += game->ball.dx * (game->ball.speed * delta);
	game->ball.y += game->ball.dy * (game->ball.speed * delta);
	if (game->ball.y < MARGIN
			|| game->ball.y > WINDOW_HEIGHT - MARGIN - game->ball.height)
	{
		game->ball.y = previous_pos_y;
		game->ball.dy = -game->ball.dy;
	}

	if (check_collision(&game->player_1, &game->ball))
	{
		if (game->ball.y < game->player_1.y + game->player_1.height / 2)
			game->ball.dy = -1;
		else
			game->ball.dy = 1;
		game->ball.x = previous_pos_x;
		game->ball.dx = -game->ball.dx;
	}
}
