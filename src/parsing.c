/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:38:25 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 13:31:41 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_is_rectangle(char *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i] != '\n')
		i++;
	j = -1;
	while (map[++j])
	{
		k = 0;
		while (map[k] != '\n')
			k++;
		if (i != k)
			return (0);
	}
	return (1);
}

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

int	ft_parse_map(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' \
		&& map[i] != 'P' && map[i] != 'E')
		{
			printf("Invalid characters");
			return (0);
		}
	}
	if (!ft_is_rectangle(map))
	{
		printf("Invalid rectangle");
		return (0);
	}
	return (1);
}
