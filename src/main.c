/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/13 12:31:09 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->line)
		free(map->map[i]);
	free(map->map);
	map->map = NULL;
}

void	ft_init_map(t_map *map, char *map_path)
{
	*map = (t_map){0};
	map->map_path = map_path;
	ft_check_path(map);
	ft_check_dimensions(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	ft_map_reachable(map);
	ft_printf("Map is valid\n");
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_init_map(&map, argv[1]);
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx, map.col * IMG_PXL, \
		map.line * IMG_PXL, WND_NAME);
	start_game(&map);
	mlx_loop(map.mlx);
	return (0);
}
