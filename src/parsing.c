/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:38:25 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 17:36:41 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count_items(t_map *map, char type)
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

static int	ft_is_rectangle(t_map *map)
{
	int	i;
	int	len;

	if (!map || !map->map || !map->map[0])
        return (0);
	i = 0;
	len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
		{
			printf("Map is not a rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_char(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && map->map[i][j] != 'C' \
			&& map->map[i][j] != 'P' && map->map[i][j] != 'E')
			{
				printf("Invalid characters\n");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_parse_map(t_map *map)
{
	if (!ft_check_char(map) || !ft_is_rectangle(map))
	{
		ft_free_map(map);
		printf("Invalid format\n");
		return (0);
	}
	if (ft_count_items(map, 'E') != 1 || ft_count_items(map, 'P') != 1 \
	|| ft_count_items(map, 'C') < 1)
	{
		ft_free_map(map);
		printf("Invalid number of items\n");
		return (0);
	}
	return (1);
}
