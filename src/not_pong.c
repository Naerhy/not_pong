#include "not_pong.h"

int main(void)
{
	game_st game;
	int game_running;
	uint32_t previous_time;
	uint32_t current_time;
	uint32_t delta;

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
				handle_keys_down(&game.events, &game.player);
			if (game.events.type == SDL_KEYUP)
				handle_keys_up(&game.events, &game.player);
		}
		update_player(&game.player, (float)delta / 1000);
		update_opponent(&game.opponent, &game.ball, (float)delta / 1000);
		update_ball(&game.ball, &game.player, &game.opponent, (float)delta / 1000);
		draw_background(&game);
		draw_entity(game.renderer, &game.player);
		draw_entity(game.renderer, &game.opponent);
		draw_entity(game.renderer, &game.ball);
		sdl_render_present(game.renderer);
	}
	exit_game(NULL, &game);
	return EXIT_SUCCESS;
}
