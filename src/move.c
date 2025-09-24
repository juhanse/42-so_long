/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:15:39 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:55:12 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_hooks(t_data *data)
{
	mlx_hook(data->wnd, 17, 0, &quit_game, data);
	mlx_key_hook(data->wnd, key_hook, data);
}

int	ft_move(t_data *data, int axe, int pos)
{
	int	new_y;
	int	new_x;

	new_y = data->player.y;
	new_x = data->player.x;
	if (axe == W || axe == S || axe == UP || axe == DOWN)
		new_y += pos;
	if (axe == D || axe == A || axe == LEFT || axe == RIGHT)
		new_x += pos;
	if (data->map[new_y][new_x] == '1')
		return (0);
	if (data->map[new_y][new_x] == 'C')
	{
		data->collects--;
		data->map[new_y][new_x] = '0';
	}
	if (data->map[new_y][new_x] == 'E' && data->collects == 0)
		data->map[new_y][new_x] = '0';
	data->player.y = new_y;
	data->player.x = new_x;
	refresh_game(data);
	ft_printf("You moved %d\n", ++data->move_count);
	return (1);
}

void	refresh_game(t_data *data)
{
	if (!data->mlx || !data->wnd)
	{
		ft_printf("Error\nFailed to refresh game\n");
		quit_game(data);
	}
	mlx_clear_window(data->mlx, data->wnd);
	ft_fill_game(data);
	if (ft_count_items(data, 'E') == 0)
		finish_game(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP \
	|| keycode == A || keycode == LEFT)
	{
		if (!ft_move(data, keycode, -1))
			return (0);
	}
	else if (keycode == S || keycode == DOWN \
	|| keycode == D || keycode == RIGHT)
	{
		if (!ft_move(data, keycode, 1))
			return (0);
	}
	else if (keycode == ESC)
		quit_game(data);
	return (0);
}
