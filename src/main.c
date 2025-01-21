/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/21 13:13:56 by juhanse          ###   ########.fr       */
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
		return (0);
	ft_init_struct(map, argv[1]);
	ft_check_path(map);
	ft_read_map(map);
	ft_allocate_map(map);
	ft_fill_map(map);
	ft_parse_map(map);
	printf("Map is valid\n");
	// map->mlx = mlx_init();
 	// map->wnd = mlx_new_window(map->mlx, map->player.x * IMG_PXL, map->player.y * IMG_PXL, WND_NAME);
	// mlx_hook(map->wnd, 17, 0, ft_close, &map);
 	// mlx_key_hook(map->wnd, key_move, &map);
 	// mlx_loop(map->mlx);
	return (0);
}
