#include "so_long.h"

void	check_ac(int ac)
{
	if (2 < ac)
		write_error(ERROR);
}

int	check_closed_by_wall(t_map *map)
{
	int		i;
	int		j;
	char 	*map_arr;

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
	char 	*map_arr;

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

int	check_other_character(t_map *map)
{
	int		i;
	char 	*map_arr;

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
