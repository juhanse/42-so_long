/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:23:16 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:44:22 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->line)
		free(data->map[i]);
	free(data->map);
	data->map = NULL;
}

int	ft_check_path(t_data *data)
{
	int	len;

	len = ft_strlen(data->map_path);
	if (access(data->map_path, R_OK))
		return (1);
	if (data->map_path[len - 1] != 'r' || data->map_path[len - 2] != 'e' || \
	data->map_path[len - 3] != 'b' || data->map_path[len - 4] != '.')
		return (0);
	if (!ft_isalnum(data->map_path[len - 5]))
		return (0);
	return (1);
}

int	ft_initialization(t_data *data, char *map_path)
{
	data->map_path = map_path;
	if (!ft_check_path(data))
		return (perror("Error\nBad format path map\n"), 0);
	if (!ft_check_dimensions(data))
		return (perror("Error\nMap is not a rectangle\n"), 0);
	if (!ft_allocate_map(data))
		return (perror("Error\nAllocate map failed\n"), 0);
	if (!ft_fill_map(data))
		return (perror("Error\nFill map failed\n"), 0);
	ft_parse_map(data);
	ft_map_reachable(data);
	return (1);
}
