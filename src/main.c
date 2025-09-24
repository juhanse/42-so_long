/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:28:53 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (perror("Error\nInvalid arguments\n"), 1);
	map = (t_map){0};
	if (!ft_initialization(&map, argv[1]))
		return (1);
	map.mlx = mlx_init();
	map.wnd = mlx_new_window(map.mlx, map.col * IMG_PXL, \
		map.line * IMG_PXL, WND_NAME);
	ft_start_game(&map);
	mlx_loop(map.mlx);
	return (0);
}
