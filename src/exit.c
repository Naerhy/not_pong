#include "not_pong.h"

void exit_game(char const* error_msg, game_st* game)
{
	if (game->font)
		ttf_close_font(game->font);
	if (game->bg_tex)
		sdl_destroy_texture(game->bg_tex);
	if (game->renderer)
		sdl_destroy_renderer(game->renderer);
	if (game->window)
		sdl_destroy_window(game->window);
	ttf_quit();
	sdl_quit(); // safe to call this function even if sdl_init() failed
	if (error_msg)
	{
		// print error messsage
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
