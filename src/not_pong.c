#include "not_pong.h"

int main(void)
{
	game_st game;
	int game_running;
	Uint32 previous_time;
	Uint32 current_time;
	Uint32 delta;

	if (!init_game(&game))
		exit_game("not_pong: unable to initialize the game", &game);
	create_background_texture(&game); // check return error
	game_running = 1;
	previous_time = 0;
	while (game_running)
	{
		current_time = sdl_get_ticks();
		delta = current_time - previous_time;
		previous_time = current_time;
		while (sdl_poll_event(&game.events))
		{
			if (game.events.type == SDL_QUIT || (game.events.type == SDL_KEYDOWN
					&& game.events.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				game_running = 0;
			if (game.events.type == SDL_KEYDOWN)
				handle_keys_down(&game);
			if (game.events.type == SDL_KEYUP)
				handle_keys_up(&game);
		}
		update_player_pos(&game, (float)delta / 1000);
		draw_background(&game);
		draw_players(&game);
		sdl_render_present(game.renderer);
	}
	exit_game(NULL, &game);
	return EXIT_SUCCESS;
}
