/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/31 14:16:48 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_copy_map(t_map *map)
{
	int		i;
	int		j;

	map->copy = malloc(sizeof(char *) * map->line);
	if (!map->copy)
		return ;
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

void	flood_fill(t_map *map, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= map->col || move_y >= map->line || map->copy[move_x][move_y] == '1' || map->copy[move_x][move_y] == 'X')
		return ;
	if (((map->copy[move_x + 1][move_y] == 'E') || (map->copy[move_x - 1][move_y] == 'E')) && ((map->copy[move_x][move_y + 1] == '1') || (map->copy[move_x][move_y - 1] == '1')))
		return ;
	if (((map->copy[move_x][move_y + 1] == 'E') || (map->copy[move_x][move_y - 1] == 'E')) && ((map->copy[move_x + 1][move_y] == '1') || (map->copy[move_x - 1][move_y] == '1')))
		return ;
	if (map->copy[move_x][move_y] == 'E' || map->copy[move_x][move_y] == 'C')
		map->copy[move_x][move_y] = '0';
	map->copy[move_x][move_y] = 'X';
	flood_fill(map, move_x - 1, move_y);
	flood_fill(map, move_x + 1, move_y);
	flood_fill(map, move_x, move_y - 1);
	flood_fill(map, move_x, move_y + 1);
}
