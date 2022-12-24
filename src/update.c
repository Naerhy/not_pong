#include "not_pong.h"

void update_player(entity_st* player, float delta)
{
	float previous_pos_y;

	previous_pos_y = player->y;
	if (player->dy)
		player->y += player->dy * (player->speed * delta);

	if (player->y < MARGIN || player->y > WINDOW_HEIGHT - MARGIN - player->height)
		player->y = previous_pos_y;
}

void update_opponent(entity_st* opponent, entity_st* ball, float delta)
{
	float opponent_center_y;
	float ball_center_y;

	opponent_center_y = opponent->y + (opponent->height / 2);
	ball_center_y = ball->y + (ball->height / 2);
	if (ball_center_y < opponent_center_y)
		opponent->y -= (opponent->speed * delta);
	else
		opponent->y += (opponent->speed * delta);
}

static int check_collision(entity_st* ent_1, entity_st* ent_2)
{
	if (ent_1->x < ent_2->x + ent_2->width && ent_1->x + ent_1->width > ent_2->x
			&& ent_1->y < ent_2->y + ent_2->height && ent_1->y + ent_1->height > ent_2->y)
		return 1;
	return 0;
}

void update_ball(entity_st* ball, entity_st* player, entity_st* opponent, float delta)
{
	float previous_pos_x;
	float previous_pos_y;

	previous_pos_x = ball->x;
	previous_pos_y = ball->y;
	ball->x += ball->dx * (ball->speed * delta);
	ball->y += ball->dy * (ball->speed * delta);
	if (ball->y < MARGIN || ball->y > WINDOW_HEIGHT - MARGIN - ball->height)
	{
		ball->y = previous_pos_y;
		ball->dy = -ball->dy;
	}
	if (check_collision(player, ball))
	{
		if (ball->y < player->y + player->height / 2)
			ball->dy = -1;
		else
			ball->dy = 1;
		ball->x = previous_pos_x;
		ball->dx = -ball->dx;
	}
	if (check_collision(opponent, ball))
	{
		if (ball->y < opponent->y + opponent->height / 2)
			ball->dy = -1;
		else
			ball->dy = 1;
		ball->x = previous_pos_x;
		ball->dx = -ball->dx;
	}
}
