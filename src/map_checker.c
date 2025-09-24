/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:33 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:58:03 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_copy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->line)
		free(data->copy[i]);
	free(data->copy);
	data->copy = NULL;
}

static int	ft_copy_map(t_data *data)
{
	int	i;

	data->copy = malloc(data->line * sizeof(char *));
	if (!data->copy)
		return (perror("Error\nMalloc failed for map copy\n"), ft_free_map(data), 0);
	i = -1;
	while (++i < data->line)
	{
		data->copy[i] = malloc((data->col + 1) * sizeof(char));
		if (!data->copy[i])
			return (perror("Error\nMalloc failed for map copy\n"), ft_free_map(data), ft_free_copy(data), 0);
		ft_strlcpy(data->copy[i], data->map[i], data->col + 1);
	}
	return (1);
}

void	ft_flood_fill(t_data *data, int x, int y, int *collects)
{
	if (x < 0 || x >= data->line || y < 0 || y >= data->col)
		return ;
	if (data->copy[x][y] == '1')
		return ;
	if (data->copy[x][y] == 'C')
		(*collects)--;
	if (data->copy[x][y] == 'E')
		data->exit_found = 1;
	data->copy[x][y] = '1';
	ft_flood_fill(data, x - 1, y, collects);
	ft_flood_fill(data, x + 1, y, collects);
	ft_flood_fill(data, x, y - 1, collects);
	ft_flood_fill(data, x, y + 1, collects);
}

int	ft_map_reachable(t_data *data)
{
	int	collects;

	collects = data->collects;
	if (!ft_copy_map(data))
		return (0);
	ft_flood_fill(data, data->player.y, data->player.x, &collects);
	ft_free_copy(data);
	if (data->exit_found != 1 || collects != 0)
		return (perror("Error\nMap is not reachable\n"), ft_free_map(data), 0);
	return (1);
}
