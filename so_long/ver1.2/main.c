/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:15:06 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:43:28 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	so_long;
	t_map	map;
	t_img	image;

	check_ac(ac);
	init_game(&so_long);
	init_component(&map, &so_long, &image, av);
	control_function(&map, &so_long, &image);
	mlx_loop(so_long.start);
	return (0);
}
