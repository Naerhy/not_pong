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
	game->player = create_entity(PLAYER);
	game->opponent = create_entity(OPPONENT);
	game->ball = create_entity(BALL);
	return 1;
}

entity_st create_entity(entity_name_et name)
{
	entity_st entity;

	if (name == PLAYER)
	{
		entity.width = 6;
		entity.height = 60;
		entity.speed = 200;
		entity.x = MARGIN;
		entity.y = WINDOW_HEIGHT / 2 - entity.height / 2;
		entity.dx = 0;
		entity.dy = 0;
	}
	else if (name == OPPONENT)
	{
		entity.width = 6;
		entity.height = 60;
		entity.speed = 200;
		entity.x = WINDOW_WIDTH - MARGIN - entity.width;
		entity.y = WINDOW_HEIGHT / 2 - entity.height / 2;
		entity.dx = 0;
		entity.dy = 0;
	}
	else
	{
		entity.width = 10;
		entity.height = 10;
		entity.speed = 200;
		entity.x = WINDOW_WIDTH / 2 - entity.width / 2;
		entity.y = WINDOW_HEIGHT / 2 - entity.height / 2;
		entity.dx = -1;
		entity.dy = 0;
	}
	return entity;
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
