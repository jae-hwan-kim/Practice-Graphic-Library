/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:14:09 by jaekim            #+#    #+#             */
/*   Updated: 2022/06/02 11:13:21 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_closed_by_wall(t_map *map)
{
	int		i;
	int		j;
	char	*map_arr;

	i = 0;
	j = 1;
	map_arr = map->map;
	while (i < (int)map->size)
	{
		while (j <= map->columns)
		{
			if (1 == j || j == map->columns)
				if ('1' != map_arr[i])
					return (1);
			i++;
			if (1 < j && j < map->columns)
				if ('1' != map_arr[(j - 1) * map->row]
					|| '1' != map_arr[(j - 1) * map->row + (map->row - 1)])
					return (1);
			if (i % map->row == 0)
				break ;
		}
		j++;
	}
	return (0);
}

int	check_other_character(t_map *map)
{
	int		i;
	char	*map_arr;

	i = 0;
	map_arr = map->map;
	while (0 != map_arr[i])
	{
		if ('0' != map_arr[i] && '1' != map_arr[i]
			&& 'C' != map_arr[i] && 'E' != map_arr[i]
			&& 'P' != map_arr[i] && 'X' != map_arr[i])
			return (1);
		else
			i++;
	}
	return (0);
}

void	check_error(t_map *map)
{
	if (check_exist(map) || check_other_character(map)
		|| check_closed_by_wall(map))
		write_error(ERROR);
}
