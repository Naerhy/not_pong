#include "not_pong.h"

void update_player(entity_st* player, float delta)
{
	float previous_pos_y;

	previous_pos_y = player->y;
	if (player->dy)
		player->y += player->dy * (player->speed * delta);

	if (player->y < MARGIN || player->y > WINDOW_HEIGHT - MARGIN - player->height)
		player->y = previous_pos_y;
	player->rect.y = (int)player->y;
}

static int check_collision(entity_st* ent_1, entity_st* ent_2)
{
	if (ent_1->x < ent_2->x + ent_2->width && ent_1->x + ent_1->width > ent_2->x
			&& ent_1->y < ent_2->y + ent_2->height && ent_1->y + ent_1->height > ent_2->y)
		return 1;
	return 0;
}

static int get_ball_impact_pos(entity_st* ball, entity_st* player)
{
	size_t i;
	float split_size;

	split_size = player->height / 5;
	for (i = 1; i <= 5; i++)
	{
		if (ball->y <= player->y + split_size * i
				|| ball->y + ball->height <= player->y + split_size * i)
			break;
	}
	return i;
}

void update_ball(entity_st* ball, entity_st* player1, entity_st* player2, float delta)
{
	float previous_pos_x;
	float previous_pos_y;
	int ball_impact;

	previous_pos_x = ball->x;
	previous_pos_y = ball->y;
	ball->x += ball->dx * (ball->speed * delta);
	ball->y += ball->dy * (ball->speed * delta);
	if (ball->y < MARGIN || ball->y > WINDOW_HEIGHT - MARGIN - ball->height)
	{
		ball->y = previous_pos_y;
		ball->dy = -ball->dy;
	}
	if (check_collision(player1, ball))
	{
		ball_impact = get_ball_impact_pos(ball, player1);
		if (ball_impact == 1)
			ball->dy = -1;
		else if (ball_impact == 2)
			ball->dy = -0.5;
		else if (ball_impact == 3)
			ball->dy = 0;
		else if (ball_impact == 4)
			ball->dy = 0.5;
		else
			ball->dy = 1;
		ball->x = previous_pos_x;
		ball->dx = -ball->dx;
	}
	if (check_collision(player2, ball))
	{
		ball_impact = get_ball_impact_pos(ball, player2);
		if (ball_impact == 1)
			ball->dy = -1;
		else if (ball_impact == 2)
			ball->dy = -0.5;
		else if (ball_impact == 3)
			ball->dy = 0;
		else if (ball_impact == 4)
			ball->dy = 0.5;
		else
			ball->dy = 1;
		ball->x = previous_pos_x;
		ball->dx = -ball->dx;
	}
	ball->rect.x = ball->x;
	ball->rect.y = ball->y;
}
