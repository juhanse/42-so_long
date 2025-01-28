/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 12:52:49 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_player_move(t_map *map, char pos, int direction)
{
	if (pos == 'y' && direction == UP)
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets->up, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (pos == 'x' && direction == LEFT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets->left, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (pos == 'y' && direction == DOWN)
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets->down, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (pos == 'x' && direction == RIGHT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->assets->right, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
}

void	ft_move(t_map *map, char pos, int dir)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->assets[1].img, (map->player.x * IMG_PXL), (map->player.y * IMG_PXL));
	if (pos == 'y' && map->map[map->player.y + 1 * dir][map->player.x] != '1' && map->map[map->player.y + 1 * dir][map->player.x] != 'E')
	{
		printf("Move\n");
		map->player.y = map->player.y + 1 * dir;
	}
	else if (pos == 'x' && map->map[map->player.y][map->player.x + 1 * dir] != '1' && map->map[map->player.y][map->player.x + 1 * dir] != 'E')
	{
		printf("Move\n");
		map->player.x = map->player.x + 1 * dir;
	}
	// else if (pos == 'y' && map->map[map->player.y + 1 * dir][map->player.x] == 'E' && map->collected != map->map->diamonds)
	// 	printf("Collect all collectibles before leaving\n");
	// else if (pos == 'x' && map->map[map->player.y][map->player.x + 1 * dir] == 'E' && map->collected != map->map->diamonds)
	// 	printf("Collect all collectibles before leaving\n");
	ft_player_move(map, pos, dir);
	// if (map->map[map->player.y][map->player.x] == 'C')
	// 	ft_collect(map, pos, dir);
	mlx_do_sync(map->mlx);
	printf("You moved %d times.\n", ++map->move_count);
}
