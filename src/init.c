/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:23:16 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:23:24 by juhanse          ###   ########.fr       */
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

void	ft_initialization(t_map *map, char *map_path)
{
	map->map_path = map_path;
	ft_check_path(map);
	ft_check_dimensions(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	ft_map_reachable(map);
}
