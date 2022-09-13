/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:30:33 by jaekim            #+#    #+#             */
/*   Updated: 2022/01/01 12:49:04 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_check_get_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup[i])
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_save_backup(char *backup)
{
	char	*line;
	int		i;
	int		c;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!line)
		return (0);
	c = 0;
	i++;
	while (backup[i])
		line[c++] = backup[i++];
	free (backup);
	line[c] = 0;
	return (line);
}

char	*ft_read(int fd, char *backup)
{
	char	*buf;
	int		read_bytes;
	char	*ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(backup, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		// backup 을 해제하지 않았는데 backup 의 값을 덮어씀.
		ret = ft_strjoin(backup, buf);
		free(backup);
		backup = ret;
	}
	free (buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read(fd, backup);
	if (!backup)
	{
		free (backup);
		return (0);
	}
	line = ft_check_get_line(backup);
	backup = ft_save_backup(backup);
	return (line);
}
