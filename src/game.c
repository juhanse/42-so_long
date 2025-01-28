/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 13:09:11 by juhanse          ###   ########.fr       */
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
	map->assets[index].up = 0;
	map->assets[index].down = 0;
	map->assets[index].right = 0;
	map->assets[index].left = 0;
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
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[2].img, j * IMG_PXL, i * IMG_PXL);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->wnd, map->assets[3].img, j * IMG_PXL, i * IMG_PXL);
		}
	}
}

// int	key_hook(int keycode, t_map *map)
// {
// 	// if (keycode == ESC)
// 	// 	ft_exit(map);
// 	(void)keycode;
// 	(void)map;
// 	printf("MOVE");
// 	// if (keycode == W)
// 	// {
// 	// 	printf("W");
// 	// 	ft_move(map, 'y', UP);
// 	// }
// 	// else if (keycode == A)
// 	// 	ft_move(map, 'x', LEFT);
// 	// else if (keycode == S)
// 	// 	ft_move(map, 'y', DOWN);
// 	// else if (keycode == D)
// 	// 	ft_move(map, 'x', RIGHT);
// 	// if (map->map->map[map->p_y][map->p_x] == 'E')
// 	// 	winner(map);
// 	return (0);
// }

int	key_hook(int keycode, t_map *map)
{
	(void)map;
	printf("MOVE\n");
	if (keycode == W)
		printf("W\n");
	else if (keycode == S)
		printf("S\n");
	else if (keycode == A)
		printf("A\n");
	else if (keycode == D)
		printf("D\n");
	else if (keycode == UP)
		printf("UP\n");
	else if (keycode == DOWN)
		printf("DOWN\n");
	else if (keycode == RIGHT)
		printf("RIGHT\n");
	else if (keycode == LEFT)
		printf("LEFT\n");
	else if (keycode == ESC)
	{
		printf("ESC\n");
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->wnd = mlx_new_window(map->mlx, X, Y, WND_NAME);
	load_img(map, "./assets/wall2.xpm", 0);
	load_img(map, "./assets/player.xpm", 1);
	load_img(map, "./assets/collect.xpm", 2);
	load_img(map, "./assets/exit.xpm", 3);
	fill_game(map);
	mlx_key_hook(map->wnd, key_hook, &map);
	mlx_loop(map->mlx);
}
