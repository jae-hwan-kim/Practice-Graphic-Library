/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:13:55 by jaekim            #+#    #+#             */
/*   Updated: 2022/05/30 18:13:56 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_error(char *error)
{
	perror(error);
	exit(1);
}

int	window_close(void)
{
	system("leaks so_long");
	exit(0);
}
