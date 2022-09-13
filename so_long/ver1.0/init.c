#include "so_long.h"

void	init_put_img(t_draw *put_img, t_img *image, t_game *game, t_map *map)
{
	put_img->game = game;
	put_img->image = image;
	put_img->map = map;
}

void	init_player(t_player *player, t_game *game, t_map *map, t_img *image)
{
	player->game = game;
	player->map = map;
	player->image = image;
	player->position = 0;
	player->x = 0;
	player->y = 0;
	player->move_count = 0;
}

void	init_component(t_map *map, t_game *so_long, t_img *image, char **av)
{
	(void)	image;
	(void)	so_long;

	malloc_map(map, av);
	get_mapinfo(map, av);
	check_error(map);
	get_windowinfo(so_long, map);
	init_window(so_long);
	get_imageinfo(image, so_long, map);
}

void	init_window(t_game *so_long)
{
	so_long->window = mlx_new_window(so_long->start, so_long->width, so_long->height, GAMENAME);
}

void	init_game(t_game *game)
{
	game -> start = mlx_init();
	if (NULL == game -> start)
		write_error(ERROR);
}