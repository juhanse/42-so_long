/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 16:43:20 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	load_img(t_map *map, char *path, int index)
{
	if (!path || map->assets[index].img)
	{
		printf("Failed load image\n");
		exit(EXIT_FAILURE);
	}
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
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[0].img, j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'P' && map->player_started == 0)
			{
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, j * IMG_PXL, i * IMG_PXL);
				map->player.x = j * IMG_PXL;
				map->player.y = i * IMG_PXL;
				map->player_started = 1;
			}
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[2].img, j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[3].img, j * IMG_PXL, i * IMG_PXL);
		}
	}
}

void	quit_game(t_map *map)
{
	ft_free_map(map);
	mlx_destroy_window(map->mlx, map->wnd);
	printf("Leave game\n");
	exit(EXIT_FAILURE);
}

void	start_game(t_map *map)
{
	load_img(map, "./assets/wall2.xpm", 0);
	load_img(map, "./assets/player.xpm", 1);
	load_img(map, "./assets/collect.xpm", 2);
	load_img(map, "./assets/exit.xpm", 3);
	fill_game(map);
}
