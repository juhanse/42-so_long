/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/21 15:14:15 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	load_img(t_map *map, char *path, int index)
{
	if (!path)
		exit(EXIT_FAILURE);
	map->assets[index].path = path;
	map->assets[index].width = IMG_PXL;
	map->assets[index].height = IMG_PXL;
	map->assets[index].img = mlx_xpm_file_to_image(map->mlx, path, &map->assets[index].width, &map->assets[index].height);
	if (!map->assets[index].img)
	{
		printf("Failed load image\n");
		exit(EXIT_FAILURE);
	}
}

void	fill_game(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, i, j);
	}
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->wnd = mlx_new_window(map->mlx, X, Y, WND_NAME);
	load_img(map, "./assets/wall.xpm", 1);
	fill_game(map);
	mlx_loop(map->mlx);
}
