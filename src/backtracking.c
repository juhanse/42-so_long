/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/31 11:57:03 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**ft_copy_map(t_map *map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc(sizeof(char *) * map->line);
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < map->line)
	{
		map_copy[i] = malloc(sizeof(char) * map->col);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		j = -1;
		while (++j < map->col)
			map_copy[i][j] = map->map[i][j];
	}
	return (map_copy);
}

int	flood_fill(t_map *map, char **map_copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->line || y >= map->col || map_copy[x][y] == '1')
		return (0);
	if (map_copy[x][y] == 'E' && map->collects != 0)
		return (1);
	if (map_copy[x][y] == 'C')
		map->collects--;
	map_copy[x][y] = '1';
	if (flood_fill(map, map_copy, x + 1, y) || flood_fill(map, map_copy, x - 1, y) || flood_fill(map, map_copy, x, y + 1) || flood_fill(map, map_copy, x, y - 1))
		return (1);
	return (0);
}

int	ft_is_valid_map(t_map *map)
{
	char	**map_copy;
	int		valid;
	int		i;

	map_copy = ft_copy_map(map);
	if (!map_copy)
		return (0);
	i = -1;
	valid = flood_fill(map, map_copy, map->player.x, map->player.y);
	while (++i < map->line)
		free(map_copy[i]);
	free(map_copy);
	return (valid && map->collects == 0);
}
