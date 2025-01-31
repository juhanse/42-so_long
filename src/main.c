/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/31 14:17:40 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_init_map(t_map *map, char *map_path)
{
	if (!map_path)
	{
		printf("Invalid map file\n");
		exit(EXIT_FAILURE);
	}
	*map = (t_map){0};
	map->map_path = map_path;
	ft_check_path(map);
	ft_read_map(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	ft_copy_map(map);
	flood_fill(map, map->player.x, map->player.y);
	printf("Map is valid\n");
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	ft_init_map(&map, argv[1]);
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx, X, Y, WND_NAME);
	printf("\nMAIN: %d | %d\n", map.player.y, map.player.x);
	start_game(&map);
	mlx_loop(map.mlx);
	return (0);
}
