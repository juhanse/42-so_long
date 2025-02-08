/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:34:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/08 15:44:50 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	map->map = NULL;
}

void	ft_check_path(t_map *map)
{
	int	len;

	len = ft_strlen(map->map_path);
	if (map->map_path[len - 1] != 'r' || map->map_path[len - 2] != 'e' || \
	map->map_path[len - 3] != 'b' || map->map_path[len - 4] != '.')
	{
		ft_printf("Error\nBad path map\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_isalnum(map->map_path[len - 5]))
	{
		ft_printf("Error\nBad path map\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_read_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMissing map file\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map->col = ft_strlen(line) - 1;
	while (line)
	{
		ft_printf("%s | %d\n", line, ft_strlen(line) - 1);
		if (ft_strlen(line) - 1 != map->col)
		{
			ft_printf("Error\nMap is not a rectangle\n");
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		map->line++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_allocate_map(t_map *map)
{
	int	i;

	i = -1;
	map->map = (char **)malloc(sizeof(char *) * (map->line + 1));
	if (!map->map)
		return ;
	while (++i < map->line)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->col + 1));
		if (!map->map[i])
		{
			ft_free_map(map);
			return ;
		}
	}
	map->map[map->line] = NULL;
}

void	ft_fill_map(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		ft_strlcpy(map->map[i], line, map->col + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
