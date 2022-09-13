/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:14:16 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:41:57 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ac(int ac)
{
	if (2 < ac)
		write_error(ERROR);
}

int	check_amount(char *map_arr, char check_char)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (0 != map_arr[index])
	{
		if (check_char == map_arr[index])
			count++;
		index++;
	}
	if (count >= 2)
		return (1);
	return (0);
}

int	check_exist(t_map *map)
{
	int		i;
	char	*map_arr;

	i = 0;
	map_arr = map->map;
	if (!ft_strchr(map_arr, '0'))
		return (1);
	if (!ft_strchr(map_arr, '1'))
		return (1);
	if (!ft_strchr(map_arr, 'C'))
		return (1);
	if (!ft_strchr(map_arr, 'E') || check_amount(map_arr, 'E'))
		return (1);
	if (!ft_strchr(map_arr, 'P') || check_amount(map_arr, 'P'))
		return (1);
	return (0);
}
