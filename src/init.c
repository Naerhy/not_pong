#include "not_pong.h"

int init_game(game_st* game)
{
	game->window = NULL;
	game->renderer = NULL;
	game->bg_tex = NULL;
	if (sdl_init(SDL_INIT_VIDEO))
		return 0;
	game->window = sdl_create_window("not_pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!game->window)
		return 0;
	game->renderer = sdl_create_renderer(game->window, -1, SDL_RENDERER_ACCELERATED);
	if (!game->renderer)
		return 0;
	init_player(game);
	return 1;
}

void init_player(game_st* game)
{
	game->player_1.width = 6;
	game->player_1.height = 60;
	game->player_1.speed = 200;
	game->player_1.direction = 0;
	game->player_1.x = 10;
	game->player_1.y = WINDOW_HEIGHT / 2 - game->player_1.height / 2;
}

void create_background_texture(game_st* game)
{
	int line_width;
	int space;
	sdl_rect rect;

	game->bg_tex = sdl_create_texture(game->renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HEIGHT);
	// check return error
	sdl_set_render_target(game->renderer, game->bg_tex);
	sdl_set_render_draw_color(game->renderer, 0, 0, 0, 255);
	sdl_render_clear(game->renderer);
	sdl_set_render_draw_color(game->renderer, 67, 67, 67, 255);
	line_width = 5;
	space = 40;
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		if (y % 2 == 1)
		{
			rect = create_rectangle(WINDOW_WIDTH / 2 - line_width / 2, y * space, line_width, space);
			sdl_render_fill_rect(game->renderer, &rect);
		}
	}
	// rect = create_rectangle(WINDOW_WIDTH / 2 - line_width / 2, 0, line_width, WINDOW_HEIGHT);
	// sdl_render_fill_rect(game->renderer, &rect);
	sdl_set_render_target(game->renderer, NULL);
	game->bg_tex_rect = create_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

sdl_rect create_rectangle(int x, int y, int w, int h)
{
	sdl_rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return rect;
}
