#include "so_long.h"

void	set_position(t_player *player)
{
	int			i;
	char		*map_arr;
	
	i = 0;
	map_arr= player->map->map;
	while (0 != map_arr[i])
	{
		if ('P' == map_arr[i])
			break;	
		i++;
	}
	player->position = i;
	player->x = (player->position % player->map->row);
	player->y = (player->position) / player->map->row;
}

int	check_wall(t_player *player, int keycode)
{
	int	position;
	int	row;
	char	*map_arr;

	map_arr = player->map->map;
	position = player->position;
	row = player->map->row;
	if (keycode == KEY_W && '1' == map_arr[position - row])
			return (1);
	if (keycode == KEY_S && '1' == map_arr[position + row])
			return (1);
	if (keycode == KEY_A && '1' == map_arr[position - 1])
			return (1);
	if (keycode == KEY_D && '1' ==  map_arr[position + 1])
			return (1);
	return (0);
}

int	check_c(char *map_arr)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (0 != map_arr[index])
	{
		if ('C' == map_arr[index])
			count++;
		index++;
	}
	if (0 == count)
		return (0);
	return (1);
}

int	check_exit(t_player *player, int keycode)
{
	int		position;
	int		row;
	void	*id;
	char	*map_arr;

	map_arr = player->map->map;
	position = player->position;
	row = player->map->row;
	if ((keycode == KEY_W && 'E' == map_arr[position - row]) ||
		(keycode == KEY_S && 'E' == map_arr[position + row]) ||
		(keycode == KEY_A && 'E' == map_arr[position - 1]) ||
		(keycode == KEY_D && 'E' ==  map_arr[position + 1]))
	{
		if (check_c(map_arr))
			return (1);
		else
		{
			map_arr[position] = '0';
			id = mlx_xpm_file_to_image(player->game, EMPTY, &player->image->width, &player->image->height);
			mlx_put_image_to_window(player->game, player->game->window, id, TILE * player->x, TILE * player->y);
			return (1);
		}
	}
	return (0);
}

int	gameable(char *map_arr)
{
	int	index;

	index = 0;
	while (0 != map_arr[index])
	{
		if ('P' == map_arr[index])
			return (1);
		index++;
	}
	return (0);
}

void	draw_empty(t_player *player, int keycode)
{
	void 	*id;
	char	*map_arr;

	map_arr = player->map->map;
	map_arr[player->position] = '0';
	id = mlx_xpm_file_to_image(player->game, EMPTY, &player->image->width, &player->image->height);
	mlx_put_image_to_window(player->game, player->game->window, id, TILE * player->x, TILE * player->y);
	if (keycode == KEY_W)
		player->position = player->position - player->map->row;
	if (keycode == KEY_S)
		player->position = player->position + player->map->row;
	if (keycode == KEY_A)
		player->position = player->position - 1;
	if (keycode == KEY_D)
		player->position = player->position + 1;
}

void	draw_player(t_player *player)
{
	void 	*id;
	char	*map_arr;

	map_arr = player->map->map;
	map_arr[player->position] = 'P';
	set_position(player);
	id = mlx_xpm_file_to_image(player->game, PLAYER, &player->image->width, &player->image->height);
	mlx_put_image_to_window(player->game, player->game->window, id, TILE * player->x, TILE * player->y);
}

int	change_image(t_player *player, int keycode)
{
	if (check_wall(player, keycode) || check_exit(player, keycode))
		return (1);
	draw_empty(player, keycode);
	draw_player(player);
	player -> move_count++;
		printf("move count : %d\n", player->move_count);
	return (0);
}

int	press_key(int keycode, t_player *player)
{
	set_position(player);
	if (gameable(player->map->map))
	{
		if (keycode == KEY_W && change_image(player, keycode))
			return (0);
		else if (keycode == KEY_S && change_image(player, keycode))
			return (0);
		else if (keycode == KEY_A && change_image(player, keycode))
			return (0);
		else if (keycode == KEY_D && change_image(player, keycode))
			return (0);
		else if (keycode == KEY_ESC)
			window_close();
		else
			return (0);
	}
	else if (keycode == KEY_ESC)
		window_close();
	return (0);
}

void	control_function(t_map *map, t_game *game, t_img *image)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	init_player(player, game, map, image);
	mlx_hook(player->game->window, X_EVENT_KEY_PRESS, 0, &press_key, player);
	mlx_hook(player->game->window, RED_CROSS, 0, &window_close, 0);
}

int		main(int ac, char **av)
{
	t_game	so_long;
	t_map	map;
	t_img	image;
	(void) ac;

	check_ac(ac);
	init_game(&so_long);
	init_component(&map, &so_long, &image, av);
	control_function(&map, &so_long, &image);
	mlx_loop(so_long.start);
	return (0);
}