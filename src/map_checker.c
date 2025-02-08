/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/08 18:33:04 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_copy(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->line)
		free(map->copy[i]);
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
		ft_printf("Error\nMalloc failed for map copy\n");
		ft_free_copy(map);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < map->line)
	{
		map->copy[i] = malloc(sizeof(char) * (map->col + 1));
		if (!map->copy[i])
		{
			ft_printf("Error\nMalloc failed for map copy\n");
			ft_free_copy(map); //free map aussi
			exit(EXIT_FAILURE);
		}
		j = -1;
		while (++j < map->col)
			map->copy[i][j] = map->map[i][j];
	}
}

void	flood_fill(t_map *map, int x, int y, int *collects)
{
	if (x < 0 || x >= map->line || y < 0 || y >= map->col)
		return ;
	if (map->copy[x][y] == '1')
		return ;
	if (map->copy[x][y] == 'C')
		(*collects)--;
	if (map->copy[x][y] == 'E')
		map->exit_found = 1;
	map->copy[x][y] = '1';
	flood_fill(map, x - 1, y, collects);
	flood_fill(map, x + 1, y, collects);
	flood_fill(map, x, y - 1, collects);
	flood_fill(map, x, y + 1, collects);
}

void	ft_map_reachable(t_map *map)
{
	int	collects;

	collects = map->collects;
	ft_copy_map(map);
	flood_fill(map, map->player.y, map->player.x, &collects);
	ft_free_copy(map);
	if (map->exit_found != 1 || collects != 0)
	{
		ft_printf("Error\nMap is not reachable\n");
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
}
