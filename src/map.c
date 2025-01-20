/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 16:12:59 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_read_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (write(1, "Error", 5));
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->map[map->line] = get_next_line(fd);
		map->line++;
	}
	close(fd);
	free(line);
}

t_map	ft_init_map(char *map_path)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc()
	map->data = ft_split(get_next_line(map_path), "\n");
}
