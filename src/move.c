/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 16:43:08 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_move(t_map *map, char axe, int direction)
{
	if (axe == 'y' && (direction == W || direction == UP))
	{
		printf("3\n");
		if (!map->mlx || !map->wnd)
			printf("BAD\n");
		printf("4\n");
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, map->player.x * IMG_PXL, (map->player.y + 1) * IMG_PXL);
		printf("5\n");
		map->player.y = (map->player.y + 1) * IMG_PXL;
		printf("6\n");
	}
	if (axe == 'y' && (direction == S || direction == DOWN))
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, map->player.x * IMG_PXL, (map->player.y - 1) * IMG_PXL);
		map->player.y = (map->player.y - 1) * IMG_PXL;
	}
	if (axe == 'x' && (direction == D || direction == RIGHT))
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, (map->player.x + 1) * IMG_PXL, map->player.y * IMG_PXL);
		map->player.x = (map->player.x + 1) * IMG_PXL;
	}
	if (axe == 'x' && (direction == A || direction == LEFT))
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, (map->player.x - 1) * IMG_PXL, map->player.y * IMG_PXL);
		map->player.x = (map->player.x - 1) * IMG_PXL;
	}
	printf("7\n");
	mlx_do_sync(map->mlx);
	printf("8\n");
	printf("You moved %d\n", ++map->move_count);
	printf("9\n");
}

int	key_hook(int keycode, t_map *map)
{
	printf("1\n");
	if (keycode == W || keycode == UP)
	{
		printf("2\n");
		ft_move(map, 'y', UP);
	}
	else if (keycode == S || keycode == DOWN)
		ft_move(map, 'y', DOWN);
	else if (keycode == A || keycode == LEFT)
		ft_move(map, 'x', LEFT);
	else if (keycode == D || keycode == RIGHT)
		ft_move(map, 'x', RIGHT);
	else if (keycode == ESC)
	{
		printf("ESC\n");
		quit_game(map);
	}
	return (0);
}
