/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 16:19:29 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	ft_initialize_map(argv[1]);
	if (!ft_parse_map(map->map))
		return (0);
// 	ft_initialize(&map, argv);
// 	map.mlx = mlx_init();
// 	map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL, map.y * IMG_PXL, WND_NAME);
// /* 	mlx_hook(map.wnd, 17, 0, ft_close, &map);
// 	mlx_key_hook(map.wnd, key_move, &map); */
// 	mlx_loop(map.mlx);
	return (0);
}
