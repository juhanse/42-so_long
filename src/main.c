/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 12:44:36 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_struct(t_map *map, char *path)
{
	if (!path)
		write(1, "Error", 5);
	map->map_path = path;
	map->map = NULL;
	map->mlx = NULL;
	map->wnd = NULL;
	map->line = 0;
	map->col = 0;
	map->collects = 0;
	map->exit = 0;
	map->player_start = 0;
	map->move_count = 0;
	map->player.x = 0;
	map->player.y = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	ft_init_struct(map, argv[1]);
	ft_check_path(map);
	ft_read_map(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	printf("Map is valid\n");
	start_game(map);
	return (0);
}
