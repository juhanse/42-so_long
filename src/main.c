/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:16:38 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/16 14:11:26 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	main(void)
{
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;

	y = -1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, X, Y, "So Long");
	while (++y < Y)
	{
		x = -1;
		while (++x < X)
			mlx_pixel_put(mlx, mlx_win, x, y, 0xff0000);
	}
	mlx_loop(mlx);
	return (0);
}
