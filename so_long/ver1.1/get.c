/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:14:41 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:14:42 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_imageinfo(t_img *image, t_game *so_long, t_map *map)
{
	t_draw	*put_img;

	image->height = TILE;
	image->width = TILE;
	image->id = 0;
	put_img = (t_draw *)malloc(sizeof(t_draw));
	if (0 == put_img)
		write_error(ERROR);
	init_put_img(put_img, image, so_long, map);
	draw(put_img);
	free(put_img);
}

void	get_windowinfo(t_game *so_long, t_map *map)
{
	so_long->width = map->row * TILE;
	so_long->height = map->columns * TILE;
}

int	row_length(char *gnl)
{
	int	 i;

	i = 0;
	if (!gnl)
		return (0);
	while (gnl[i] && '\n' != gnl[i])
		i++;
	return (i);
}

void	get_mapinfo(t_map *map, char **av)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	map->fd = open(av[1], O_RDONLY);
	temp = get_next_line(map->fd);
	while (0 != temp)
	{
		j = 0;
		while (0 != temp[j] && '\n' != temp[j])
		{
			map->map[i] = temp[j];
			i++;
			j++;
		}
		free (temp);
		temp = get_next_line(map->fd);
	}
	close(map->fd);
}

void	malloc_map(t_map *map, char **av)
{
	char	*temp;

	map->fd = open(av[1], O_RDONLY);
	temp = get_next_line(map->fd);
	map->row = row_length(temp);
	map->columns = 0;
	while (0 != temp)
	{
		if (map->row != row_length(temp))
			write_error(ERROR);
		free (temp);
		temp = get_next_line(map->fd);
		map->columns++;
	}
	map->size = map->columns * map->row;
	map->map = malloc(sizeof(char) * (map->size + 1));
	map->map[map->size] = 0;
	close(map->fd);
}