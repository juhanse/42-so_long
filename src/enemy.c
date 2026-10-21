/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:02:08 by juhanse           #+#    #+#             */
/*   Updated: 2026/10/21 17:11:41 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	lose_game(t_data *data)
{
	ft_printf("\x1B[31m💀 Game Over! You were caught by an enemy!\x1B[0m\n");
	ft_quit_game(data);
}

void	ft_find_enemy(t_data *data)
{
	int	i;
	int	j;

	data->enemy.exists = 0;
	data->enemy.x = 0;
	data->enemy.y = 0;
	data->enemy.dir = 1;
	data->enemy.timer = 0;
	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->col)
		{
			if (data->map[i][j] == 'A')
			{
				data->enemy.x = j;
				data->enemy.y = i;
				data->enemy.exists = 1;
				data->map[i][j] = '0';
				return ;
			}
		}
	}
}

static int	is_valid_tile(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->col || y < 0 || y >= data->line)
		return (0);
	if (data->map[y][x] == '1')
		return (0);
	return (1);
}

static int	ft_choose_dir(t_data *data, int x, int y, int dir)
{
	int	dx[4] = DIR_X;
	int	dy[4] = DIR_Y;
	int	tries;

	tries = 0;
	while (tries < 4)
	{
		if (is_valid_tile(data, x + dx[dir], y + dy[dir]))
			return (dir);
		dir = (dir + 1) % 4;
		tries++;
	}
	return (dir);
}

void	ft_enemy_patrol(t_data *data)
{
	int	dx[4] = DIR_X;
	int	dy[4] = DIR_Y;

	if (!data->enemy.exists)
		return ;
	data->enemy.dir = ft_choose_dir(data, data->enemy.x, \
		data->enemy.y, data->enemy.dir);
	if (is_valid_tile(data, data->enemy.x + dx[data->enemy.dir], \
		data->enemy.y + dy[data->enemy.dir]))
	{
		data->enemy.x += dx[data->enemy.dir];
		data->enemy.y += dy[data->enemy.dir];
	}
	if (data->enemy.x == data->player.x && \
		data->enemy.y == data->player.y)
		lose_game(data);
}
