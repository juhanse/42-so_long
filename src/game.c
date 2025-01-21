/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/21 14:22:08 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
 	map->wnd = mlx_new_window(map->mlx, 1200, 600, WND_NAME);
	// mlx_hook(map->wnd, 17, 0, ft_close, &map);
 	// mlx_key_hook(map->wnd, key_move, &map);
 	mlx_loop(map->mlx);
}
