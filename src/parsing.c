/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:38:25 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:46:05 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_items(t_data *data, char type)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->col)
		{
			if (data->map[i][j] == type)
				count++;
		}
	}
	return (count);
}

int	ft_check_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->col)
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' && \
			data->map[i][j] != 'C' && data->map[i][j] != 'P' && \
			data->map[i][j] != 'E')
			{
				ft_printf("Error\nInvalid characters\n");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_walls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->col)
		{
			if (i == 0 || i == data->line - 1 || j == 0 || j == data->col - 1)
			{
				if (data->map[i][j] != '1')
				{
					ft_printf("Error\nMissing walls\n");
					return (0);
				}
			}
		}
	}
	return (1);
}

void	ft_find_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (++j < data->col)
		{
			if (data->map[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				return ;
			}
		}
	}
}

int	ft_parse_map(t_data *data)
{
	if (!data->map[0])
		return (perror("Error\nMap is empty\n"), ft_free_map(data), 0);
	if (!ft_check_char(data) || !ft_check_walls(data))
		return (perror("Error\nInvalid char\n"), ft_free_map(data), 0);
	if (ft_count_items(data, 'E') != 1 || ft_count_items(data, 'P') != 1 || ft_count_items(data, 'C') < 1)
		return (perror("Error\nInvalid number of items\n"), ft_free_map(data), 0);
	data->collects = ft_count_items(data, 'C');
	ft_find_player(data);
	return (1);
}
