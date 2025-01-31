/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/31 15:07:58 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_copy_map(t_map *map)
{
	int	i;
	int	j;

	map->copy = malloc(sizeof(char *) * map->line);
	if (!map->copy)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < map->line)
	{
		map->copy[i] = malloc(sizeof(char) * map->col);
		if (!map->copy[i])
		{
			while (--i >= 0)
				free(map->copy[i]);
			free(map->copy);
			return ;
		}
		j = -1;
		while (++j < map->col)
			map->copy[i][j] = map->map[i][j];
	}
}

int	flood_fill(char **map, int x, int y, int *collects)
{
	if (x < 0 || y < 0 || map[x][y] == '1')
		return (0);
	if (map[x][y] == 'E' && *collects == 0)
		return (1);
	if (map[x][y] == 'C')
		(*collects)--;
	map[x][y] = '1';
	if (flood_fill(map, x - 1, y, collects) || flood_fill(map, x + 1, y, collects) || flood_fill(map, x, y - 1, collects) || flood_fill(map, x, y + 1, collects))
		return (1);
	return (0);
}

int	is_map_reachable(t_map *map)
{
	int	result;
	int	collects;

	collects = map->collects;
	ft_copy_map(map);
	result = flood_fill(map->copy, map->player.y, map->player.x, &collects);
	return (result && collects == 0);
}
