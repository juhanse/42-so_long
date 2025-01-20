/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 17:17:59 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_init_struct(t_map *map, char *path)
{
	if (!path)
		write(1, "Error", 5);
	map->map_path = path;
	map->map = NULL;
	map->line = 0;
	map->col = 0;
	map->collects = 0;
	map->exit = 0;
	map->player_start = 0;
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
    {
        printf("Memory allocation failed\n");
        return (0);
    }
	ft_init_struct(map, argv[1]);
	ft_read_map(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	if (!ft_parse_map(map))
		return (0);
	printf("Map is valid\n");
// 	ft_initialize(&map, argv);
// 	map.mlx = mlx_init();
// 	map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL, map.y * IMG_PXL, WND_NAME);
// /* 	mlx_hook(map.wnd, 17, 0, ft_close, &map);
// 	mlx_key_hook(map.wnd, key_move, &map); */
// 	mlx_loop(map.mlx);
	return (0);
}
