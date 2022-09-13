/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:30:33 by jaekim            #+#    #+#             */
/*   Updated: 2022/06/02 11:06:50 by jaekim           ###   ########.fr       */
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
	if (0 == line)
		return (0);
	c = 0;
	i++;
	while (backup[i])
		line[c++] = backup[i++];
	free (backup);
	line[c] = 0;
	return (line);
}

char	*ft_read(int fd, char **backup)
{
	char	*buf;
	char	*ret;
	int		read_bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (0 == buf)
		return (0);
	read_bytes = 1;
	ret = *backup;
	while (0 != read_bytes && 0 == ft_strchr(*backup, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		*backup = ft_strjoin(ret, buf);
	}
	free (buf);
	return (*backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_backup;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_backup = ft_read(fd, &backup);
	if (!line_backup)
	{
		free (line_backup);
		return (0);
	}
	line = ft_check_get_line(line_backup);
	backup = ft_save_backup(line_backup);
	return (line);
}
