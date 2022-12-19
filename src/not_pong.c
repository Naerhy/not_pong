#include "not_pong.h"

int main(void)
{
	game_st game;
	int game_running;

	if (!init_game(&game))
		exit_game("not_pong: unable to initialize the game", &game);
	create_background_texture(&game); // check return error
	game_running = 1;
	while (game_running)
	{
		while (sdl_poll_event(&game.events))
		{
			if (game.events.type == SDL_QUIT || (game.events.type == SDL_KEYDOWN
					&& game.events.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				game_running = 0;
		}
		draw_background(&game);
		draw_players(&game);
		sdl_render_present(game.renderer);
	}
	exit_game(NULL, &game);
	return EXIT_SUCCESS;
}
