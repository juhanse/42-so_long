/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:35:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (perror("Error\nInvalid arguments\n"), 1);
	data = (t_data){0};
	if (!ft_initialization(&data, argv[1]))
		return (1);
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, data.col * IMG_PXL, \
		data.line * IMG_PXL, WND_NAME);
	ft_start_game(&data);
	mlx_loop(data.mlx);
	return (0);
}
