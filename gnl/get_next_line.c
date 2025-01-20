/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:27:01 by juhanse           #+#    #+#             */
/*   Updated: 2024/12/03 21:03:11 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_buf(int fd, char **buffer, char **tmp_buffer)
{
	int	len;

	while (!(*tmp_buffer) || !ft_strchr(*buffer, '\n'))
	{
		len = read(fd, *tmp_buffer, BUFFER_SIZE);
		if (len < 0)
		{
			free(*tmp_buffer);
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		if (len == 0)
			break ;
		(*tmp_buffer)[len] = '\0';
		*buffer = ft_line_cat(buffer, *tmp_buffer);
		if (!(*buffer))
		{
			free(*tmp_buffer);
			return (NULL);
		}
	}
	free(*tmp_buffer);
	return (*buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, (len + 1));
	return (line);
}

static char	*ft_clean_buf(char *line, char **buffer)
{
	int		start;
	int		end;
	char	*new_buffer;

	if (!line || !buffer)
		return (NULL);
	start = ft_strlen(line);
	end = ft_strlen(*buffer);
	if (end - start < 0 || end - start == 0)
	{
		free(*buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(end - start + 1);
	if (!new_buffer)
	{
		free(*buffer);
		return (NULL);
	}
	ft_strlcpy(new_buffer, *buffer + start, end - start + 1);
	free(*buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*tmp_buffer;
	char		*line;
	static char	*buffer;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	tmp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_get_buf(fd, &buffer, &tmp_buffer);
	line = ft_get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_clean_buf(line, &buffer);
	return (line);
}
