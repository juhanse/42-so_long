/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/11 15:06:26 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <string.h>
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		total;
	char	*buffer;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1)); 
	total = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc((total + 1));
	if (!buffer)
		return (NULL);
	while (s1[++i])
		buffer[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		buffer[i] = s2[j];
		i++;
	}
	buffer[total] = '\0';
	return (buffer);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	search;

	i = 0;
	search = (char) c;
	while (s[i] && s[i] != search)
		i++;
	if (s[i] == search)
		return ((char *) s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;

	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * count);
	return (buffer);
}
