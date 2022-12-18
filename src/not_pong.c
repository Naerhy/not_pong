#include "not_pong.h"

int main(void)
{
	game_st game;

	if (!init_game(&game))
		exit_game("not_pong: unable to initialize the game", &game);
	exit_game(NULL, &game);
	return EXIT_SUCCESS;
}
