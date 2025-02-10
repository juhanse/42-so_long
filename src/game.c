/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/10 16:18:47 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	load_img(t_map *map, char *path, int index)
{
	if (!path || map->assets[index].img)
	{
		ft_printf("Error\nFailed load image\n");
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	map->assets[index].path = path;
	map->assets[index].width = IMG_PXL;
	map->assets[index].height = IMG_PXL;
	map->assets[index].img = mlx_xpm_file_to_image(map->mlx, path, \
	&map->assets[index].width, &map->assets[index].height);
	if (!map->assets[index].img)
	{
		ft_printf("Error\nFailed load image\n");
		quit_game(map);
	}
}

void	fill_game(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->line)
	{
		j = -1;
		while (j++ < map->col - 1)
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[0].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[3].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[4].img, \
				j * IMG_PXL, i * IMG_PXL);
		}
	}
	mlx_put_image_to_window(map->mlx, map->wnd, map->assets[2].img, \
	map->player.x * IMG_PXL, map->player.y * IMG_PXL);
}

int	quit_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->assets[0].img);
	mlx_destroy_image(map->mlx, map->assets[1].img);
	mlx_destroy_image(map->mlx, map->assets[2].img);
	mlx_destroy_image(map->mlx, map->assets[3].img);
	mlx_destroy_image(map->mlx, map->assets[4].img);
	mlx_destroy_window(map->mlx, map->wnd);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_free_map(map);
	ft_printf("Leave game\n");
	exit(EXIT_FAILURE);
	return (0);
}

void	finish_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->assets[0].img);
	mlx_destroy_image(map->mlx, map->assets[1].img);
	mlx_destroy_image(map->mlx, map->assets[2].img);
	mlx_destroy_image(map->mlx, map->assets[3].img);
	mlx_destroy_image(map->mlx, map->assets[4].img);
	mlx_destroy_window(map->mlx, map->wnd);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_free_map(map);
	ft_printf("Leave game\n");
	ft_printf("\x1B[32m🎉 You won!\x1B[37m\n");
	exit(EXIT_SUCCESS);
}

void	start_game(t_map *map)
{
	load_img(map, "./assets/floor.xpm", 0);
	load_img(map, "./assets/wall.xpm", 1);
	load_img(map, "./assets/player.xpm", 2);
	load_img(map, "./assets/item.xpm", 3);
	load_img(map, "./assets/exit.xpm", 4);
	fill_game(map);
	ft_hooks(map);
}
