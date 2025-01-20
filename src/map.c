/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 16:25:34 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	map->map = NULL;
}

void	ft_read_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
		return (write(1, "Error", 5));
	line = get_next_line(fd);
	while (line)
	{
		map->map[map->line] = line;
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
}
