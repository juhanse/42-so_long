/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 17:05:29 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*buffer;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		buffer[i] = s2[j];
		i++;
	}
	buffer[size] = 0;
	return (buffer);
}

char	*ft_strchr(const char *str, int character)
{
	if (!str)
		return (NULL);
	while (*str || (char)character == '\0')
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (*str == character)
		return ((char *)str);
	return (NULL);
}

char	*ft_line_cat(char **s1, char *s2)
{
	char	*buffer;

	if (*s1)
		buffer = ft_strjoin(*s1, s2);
	else
		buffer = ft_strjoin("", s2);
	free(*s1);
	return (buffer);
}
