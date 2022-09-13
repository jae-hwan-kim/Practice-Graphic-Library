/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 08:30:57 by jaekim            #+#    #+#             */
/*   Updated: 2022/06/02 11:06:18 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	find;

	i = 0;
	if (!s)
		return (0);
	find = (char)c;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == find)
		return ((char *)&s[i]);
	return (0);
}

void	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && (i + 1) < size)
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = 0;
}

void	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	while (d_len + i + 1 < dstsize && src[i] != '\0')
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = src[i];
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (0 == s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (0 == s1)
			return (0);
		s1[0] = 0;
	}
	if (0 == s1 || 0 == s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (0 == str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(str) + ft_strlen(s2) + 1);
	free (s1);
	return (str);
}
