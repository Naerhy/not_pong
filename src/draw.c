#include "not_pong.h"

void draw_background(game_st* game)
{
	sdl_set_render_draw_color(game->renderer, 0, 0, 0, 255);
	sdl_render_clear(game->renderer);
	sdl_render_copy(game->renderer, game->bg_tex, NULL, &game->bg_tex_rect);
}

void draw_players(game_st* game)
{
	sdl_set_render_draw_color(game->renderer, 67, 67, 67, 255);
	sdl_render_fill_rect(game->renderer, &game->player_1);
	sdl_render_fill_rect(game->renderer, &game->player_2);
}
