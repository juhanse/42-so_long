/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:35:12 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_img(t_data *data, char *path, int index)
{
	if (!path || data->assets[index].img)
	{
		ft_printf("Error\nFailed load image\n");
		ft_free_map(data);
		exit(EXIT_FAILURE);
	}
	data->assets[index].path = path;
	data->assets[index].width = IMG_PXL;
	data->assets[index].height = IMG_PXL;
	data->assets[index].img = mlx_xpm_file_to_image(data->mlx, path, \
	&data->assets[index].width, &data->assets[index].height);
	if (!data->assets[index].img)
	{
		ft_printf("Error\nFailed load image\n");
		quit_game(data);
	}
}

void	fill_game(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->line)
	{
		j = -1;
		while (j++ < data->col)
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->wnd, data->assets[0].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->wnd, data->assets[1].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->wnd, data->assets[3].img, \
				j * IMG_PXL, i * IMG_PXL);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->wnd, data->assets[4].img, \
				j * IMG_PXL, i * IMG_PXL);
		}
	}
	mlx_put_image_to_window(data->mlx, data->wnd, data->assets[2].img, \
	data->player.x * IMG_PXL, data->player.y * IMG_PXL);
}

int	quit_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->assets[0].img);
	mlx_destroy_image(data->mlx, data->assets[1].img);
	mlx_destroy_image(data->mlx, data->assets[2].img);
	mlx_destroy_image(data->mlx, data->assets[3].img);
	mlx_destroy_image(data->mlx, data->assets[4].img);
	mlx_destroy_window(data->mlx, data->wnd);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_map(data);
	ft_printf("Leave game\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	finish_game(t_data *data)
{
	ft_printf("\x1B[32m🎉 You won!\x1B[37m\n");
	quit_game(data);
}

void	ft_start_game(t_data *data)
{
	load_img(data, "./assets/floor.xpm", 0);
	load_img(data, "./assets/wall.xpm", 1);
	load_img(data, "./assets/player.xpm", 2);
	load_img(data, "./assets/item.xpm", 3);
	load_img(data, "./assets/exit.xpm", 4);
	fill_game(data);
	ft_hooks(data);
}
