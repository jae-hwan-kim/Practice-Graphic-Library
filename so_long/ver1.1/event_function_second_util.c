/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_function_second_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:52:34 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 23:52:35 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image_for_exit(t_player *player, char *type, int x, int y)
{
	void	*id;
	void	*so_long;
	void	*window;
	int		width;
	int		height;

	width = player->image->width;
	height = player->image->height;
	id = player->image->id;
	so_long = player->game->start;
	window = player->game->window;
	player->map->map[player->position] = '0';
	id = mlx_xpm_file_to_image(so_long, type, &width, &height);
	mlx_put_image_to_window(so_long, window, id, TILE * x, TILE * y);
}
