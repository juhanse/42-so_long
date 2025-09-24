/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:43:47 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_line(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_check_dimensions(t_data *data)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	data->col = ft_strlen(line) - 1;
	while (line)
	{
		len = ft_line_len(line);
		if (len != data->col)
			return (ft_free_line(fd, line), close(fd), 0);
		free(line);
		data->line++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}

int	ft_allocate_map(t_data *data)
{
	int	i;

	i = -1;
	data->map = (char **)malloc(data->line * sizeof(char *));
	if (!data->map)
		return (0);
	while (++i < data->line)
	{
		data->map[i] = (char *)malloc((data->col + 1) * sizeof(char));
		if (!data->map[i])
			return (ft_free_map(data), 0);
	}
	return (1);
}

int	ft_fill_map(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (ft_free_map(data), 0);
	line = get_next_line(fd);
	while (line)
	{
		ft_strlcpy(data->map[++i], line, data->col + 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}
