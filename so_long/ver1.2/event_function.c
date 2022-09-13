/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:14:22 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 23:09:33 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_player *player, int keycode)
{
	int		position;
	int		row;

	position = player->position;
	row = player->map->row;
	if ((keycode == KEY_W && 'E' == player->map->map[position - row])
		|| (keycode == KEY_S && 'E' == player->map->map[position + row])
		|| (keycode == KEY_A && 'E' == player->map->map[position - 1])
		|| (keycode == KEY_D && 'E' == player->map->map[position + 1]))
	{
		if (check_c(player->map->map))
			return (1);
		else
		{
			draw_image_for_exit(player, EMPTY, player->x, player->y);
			return (1);
		}
	}
	return (0);
}

int	check_wall(t_player *player, int keycode)
{
	int		position;
	int		row;
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
	if (keycode == KEY_D && '1' == map_arr[position + 1])
		return (1);
	return (0);
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
	if (0 == player)
		write_error(ERROR);
	init_player(player, game, map, image);
	mlx_hook(player->game->window, X_EVENT_KEY_PRESS, 0, &press_key, player);
	mlx_hook(player->game->window, RED_CROSS, 0, &window_close, 0);
}
