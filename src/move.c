/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/30 15:16:07 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_hooks(t_map *map)
{
	mlx_hook(map->wnd, 17, 0, &quit_game, map);
	mlx_key_hook(map->wnd, key_hook, map);
}

void	ft_move(t_map *map, int axe, int pos)
{
    int	new_y;
    int	new_x;

	new_y = map->player.y;
	new_x = map->player.x;
    if (axe == W || axe == S)
        new_y += pos;
    if (axe == D || axe == A)
        new_x += pos;
    map->player.y = new_y;
    map->player.x = new_x;
    refresh_game(map);
    printf("\nMOVE: %d | %d\n", map->player.y, map->player.x);
    printf("You moved %d\n", ++map->move_count);
}

void	refresh_game(t_map *map)
{
	if (!map->mlx || !map->wnd)
		printf("Failed to refresh game\n");
	if (!mlx_clear_window(map->mlx, map->wnd))
		printf("Failed to clear window\n");
	fill_game(map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP || keycode == SPACE)
		ft_move(map, W, -1);
	else if (keycode == S || keycode == DOWN)
		ft_move(map, S, 1);
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
