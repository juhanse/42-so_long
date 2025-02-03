/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/03 10:27:05 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_copy(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->line)
		free(map->map[i]);
	free(map->copy);
	map->copy = NULL;
}

void	ft_copy_map(t_map *map)
{
	int	i;
	int	j;

	map->copy = malloc(sizeof(char *) * map->line);
	if (!map->copy)
		{
			printf("Malloc failed for map copy\n");
			ft_free_copy(map);
			exit(EXIT_FAILURE);
		}
	i = -1;
	while (++i < map->line)
	{
		map->copy[i] = malloc(sizeof(char) * map->col);
		if (!map->copy[i])
		{
			printf("Malloc failed for map copy\n");
			ft_free_copy(map);
			exit(EXIT_FAILURE);
		}
		j = -1;
		while (++j < map->col)
			map->copy[i][j] = map->map[i][j];
	}
}

int	flood_fill(t_map *map, int x, int y, int *collects)
{
	if (x < 0 || x >= map->line || y < 0 || y >= map->col)
		return (0);
	if (map->copy[x][y] == '1')
		return (0);
	if (map->copy[x][y] == 'E')
		return (*collects == 0);
	if (map->copy[x][y] == 'C')
		(*collects)--;
	map->copy[x][y] = '1';
	if (flood_fill(map, x - 1, y, collects) || flood_fill(map, x + 1, y, collects) || flood_fill(map, x, y - 1, collects) || flood_fill(map, x, y + 1, collects))
		return (1);
	return (0);
}

void	ft_map_reachable(t_map *map)
{
	int	result;
	int	collects;

	collects = map->collects;
	ft_copy_map(map);
	result = flood_fill(map, map->player.y, map->player.x, &collects);
	if (!result || collects != 0)
	{
		printf("Map is not reachable\n");
		ft_free_map(map);
		ft_free_copy(map);
		exit(EXIT_FAILURE);
	}
	ft_free_copy(map);
}
