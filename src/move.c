/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/05/16 01:46:23 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_hooks(t_map *map)
{
	mlx_hook(map->wnd, 17, 0, &quit_game, map);
	mlx_key_hook(map->wnd, key_hook, map);
}

int	ft_move(t_map *map, int axe, int pos)
{
	int	new_y;
	int	new_x;

	new_y = map->player.y;
	new_x = map->player.x;
	if (axe == W || axe == S || axe == UP || axe == DOWN)
		new_y += pos;
	if (axe == D || axe == A || axe == LEFT || axe == RIGHT)
		new_x += pos;
	if (map->map[new_y][new_x] == '1')
		return (0);
	if (map->map[new_y][new_x] == 'C')
	{
		map->collects--;
		map->map[new_y][new_x] = '0';
	}
	if (map->map[new_y][new_x] == 'E' && map->collects == 0)
		map->map[new_y][new_x] = '0';
	map->player.y = new_y;
	map->player.x = new_x;
	refresh_game(map);
	ft_printf("You moved %d\n", ++map->move_count);
	return (1);
}

void	refresh_game(t_map *map)
{
	if (!map->mlx || !map->wnd)
	{
		ft_printf("Error\nFailed to refresh game\n");
		quit_game(map);
	}
	mlx_clear_window(map->mlx, map->wnd);
	fill_game(map);
	if (ft_count_items(map, 'E') == 0)
		finish_game(map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP \
	|| keycode == A || keycode == LEFT)
	{
		if (!ft_move(map, keycode, -1))
			return (0);
	}
	else if (keycode == S || keycode == DOWN \
	|| keycode == D || keycode == RIGHT)
	{
		if (!ft_move(map, keycode, 1))
			return (0);
	}
	else if (keycode == ESC)
		quit_game(map);
	return (0);
}
