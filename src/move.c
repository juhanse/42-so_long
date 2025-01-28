/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 14:51:45 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_move(t_map *map, char axe, int direction)
{
	if (axe == 'y' && (direction == W || direction == UP))
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].up, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (axe == 'y' && (direction == S || direction == DOWN))
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].down, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (axe == 'x' && (direction == A || direction == LEFT))
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].left, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (axe == 'x' && (direction == D || direction == RIGHT))
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].right, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	mlx_do_sync(map->mlx);
	printf("You moved %d\n", ++map->move_count);
}

int	key_hook(int keycode, t_map *map)
{
	printf("MOVE\n");
	if (keycode == W || keycode == UP)
		ft_move(map, 'y', UP);
	else if (keycode == S || keycode == DOWN)
		ft_move(map, 'y', DOWN);
	else if (keycode == A || keycode == LEFT)
		ft_move(map, 'x', LEFT);
	else if (keycode == D || keycode == RIGHT)
		ft_move(map, 'x', RIGHT);
	else if (keycode == ESC)
	{
		printf("ESC\n");
		ft_free_map(map);
		exit(EXIT_FAILURE);
	}
	return (0);
}
