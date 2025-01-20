/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:38:25 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 13:50:22 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count_items(char *map, char type)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		if (map[i] == type)
			count++;
	}
	return (count);
}

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
	if (ft_count_items(map, 'E') != 1)
		printf("Missing exit");
	if (ft_count_items(map, 'P') != 1)
		printf("Missing start position");
	if (ft_count_items(map, 'C') < 1)
		printf("Missing collectibles items");
	return (1);
}
