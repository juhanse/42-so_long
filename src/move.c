/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/28 18:00:07 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_move(t_map *map, int axe, int pos)
{
	int	new_x;
	int	new_y;

	new_x = map->player.x;
	new_y = map->player.y;
	if (axe == W)
		new_y += pos;
	if (axe == S)
		new_y += pos;
	if (axe == D)
		new_x += pos;
	if (axe == A)
		new_x += pos;
	map->player.x = new_x;
	map->player.y = new_y;
	printf("You moved %d\n", ++map->move_count);
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
