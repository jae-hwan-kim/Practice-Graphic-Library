/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_function_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:14:33 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:45:16 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_position(t_player *player)
{
	int			i;
	char		*map_arr;

	i = 0;
	map_arr = player->map->map;
	while (0 != map_arr[i])
	{
		if ('P' == map_arr[i])
			break ;
		i++;
	}
	player->position = i;
	player->x = (player->position % player->map->row);
	player->y = (player->position) / player->map->row;
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
	char	*map_arr;

	map_arr = player->map->map;
	draw_image_for_exit(player, EMPTY, player->x, player->y);
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
	void	*id;
	void	*game;
	void	*win;
	int		width;
	int		height;

	game = player->game;
	win = player->game->window;
	width = player->image->width;
	height = player->image->height;
	player->map->map[player->position] = 'P';
	set_position(player);
	id = mlx_xpm_file_to_image(game, PLAYER, &width, &height);
	mlx_put_image_to_window(game, win, id, TILE * player->x, TILE * player->y);
}
