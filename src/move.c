/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/30 11:43:48 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_move(t_map *map, int axe, int pos)
{
	if (axe == W)
		map->player.y += pos;
	if (axe == S)
		map->player.y -= pos;
	if (axe == D)
		map->player.x += pos;
	if (axe == A)
		map->player.x -= pos;
	refresh_game(map);
	printf("You moved %d\n", ++map->move_count);
}

void	refresh_game(t_map *map)
{
	printf("\nPLAYER:\nx: %d\ny: %d\n", map->player.x, map->player.y);
	if (!map->mlx || !map->wnd)
		printf("Failed to refresh game\n");
	printf("1\n");
	mlx_clear_window(map->mlx, map->wnd);
	printf("2\n");
	fill_game(map);
	printf("3\n");
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP)
		ft_move(map, W, 1);
	else if (keycode == S || keycode == DOWN)
		ft_move(map, S, -1);
	else if (keycode == A || keycode == LEFT)
		ft_move(map, A, -1);
	else if (keycode == D || keycode == RIGHT)
		ft_move(map, D, 1);
	else if (keycode == ESC)
	{
		printf("ESC\n");
		quit_game(map);
	}
	return (0);
}
