/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:23:16 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:28:40 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->line)
		free(map->map[i]);
	free(map->map);
	map->map = NULL;
}

int	ft_check_path(t_map *map)
{
	int	len;

	len = ft_strlen(map->map_path);
	if (access(map->map_path, R_OK))
		return (1);
	if (map->map_path[len - 1] != 'r' || map->map_path[len - 2] != 'e' || \
	map->map_path[len - 3] != 'b' || map->map_path[len - 4] != '.')
		return (0);
	if (!ft_isalnum(map->map_path[len - 5]))
		return (0);
	return (1);
}

int	ft_initialization(t_map *map, char *map_path)
{
	map->map_path = map_path;
	if (!ft_check_path(map))
		return (perror("Error\nBad format path map\n"), 0);
	ft_check_dimensions(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	ft_map_reachable(map);
	return (1);
}
