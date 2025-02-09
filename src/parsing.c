/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:38:25 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/09 01:03:07 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_items(t_map *map, char type)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == type)
				count++;
		}
	}
	return (count);
}

static int	ft_check_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (j++ < map->col - 1)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && \
			map->map[i][j] != 'C' && map->map[i][j] != 'P' && \
			map->map[i][j] != 'E')
			{
				ft_printf("Error\nInvalid characters\n");
				return (0);
			}
		}
	}
	return (1);
}

static int	ft_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (i == 0 || i == map->line - 1 || j == 0 || j == map->col - 1)
			{
				if (map->map[i][j] != '1')
				{
					ft_printf("Error\nMissing walls\n");
					return (0);
				}
			}
		}
	}
	return (1);
}

static void	ft_find_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
				return ;
			}
		}
	}
}

void	ft_parse_map(t_map *map)
{
	if (!map || !map->map || !map->map[0])
	{
		ft_free_map(map);
		ft_printf("Error\nMap is empty\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_check_char(map) || !ft_check_walls(map))
	{
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	if (ft_count_items(map, 'E') != 1 || ft_count_items(map, 'P') != 1 \
	|| ft_count_items(map, 'C') < 1)
	{
		ft_free_map(map);
		ft_printf("Error\nInvalid number of items\n");
		exit(EXIT_FAILURE);
	}
	map->collects = ft_count_items(map, 'C');
	ft_find_player(map);
}
