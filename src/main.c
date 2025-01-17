/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/17 21:14:54 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_initialize(t_map *map, char **av)
{
	map->filename = av[1];
	map->player.y = 0;
	map->player.x = 0;
	map->y = 0;
	map->x = 0;
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->exit = 0;
	map->move = 0;
	map->check_c = 0;
	map->check_e = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	map_init(&map, argv);
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL, map.y * IMG_PXL, WND_NAME);
/* 	mlx_hook(map.wnd, 17, 0, ft_close, &map);
	mlx_key_hook(map.wnd, key_move, &map); */
	mlx_loop(map.mlx);
	return (0);
}
