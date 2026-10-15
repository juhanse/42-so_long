/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:23:16 by juhanse           #+#    #+#             */
/*   Updated: 2025/10/08 17:28:28 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_free_map(t_data *data) {
  int i;

  i = -1;
  while (++i < data->line)
    free(data->map[i]);
  free(data->map);
  data->map = NULL;
}

static int ft_check_path(char *path) {
  int len;

  len = ft_strlen(path);
  if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b' ||
      path[len - 4] != '.')
    return (0);
  if (!ft_isalnum(path[len - 5]))
    return (0);
  return (1);
}

int ft_initialization(t_data *data, char *map_path) {
  data->map_path = map_path;
  data->seed = 42;
  if (access(data->map_path, R_OK))
    return (perror("Error\nPermission denied\n"), 0);
  if (!ft_check_path(data->map_path))
    return (perror("Error\nBad format path map\n"), 0);
  if (!ft_check_dimensions(data))
    return (perror("Error\nMap is not a rectangle\n"), 0);
  if (!ft_allocate_map(data))
    return (perror("Error\nAllocate map failed\n"), 0);
  if (!ft_fill_map(data))
    return (perror("Error\nFill map failed\n"), 0);
  if (!ft_parse_map(data))
    return (0);
  if (!ft_map_reachable(data))
    return (perror("Error\nMap is not reachable\n"), 0);
  return (1);
}

void finish_game(t_data *data) {
  ft_printf("\x1B[32m🎉 You won!\x1B[37m\n");
  ft_quit_game(data);
}

void ft_display_moves(t_data *data) {
  char *moves;

  moves = ft_itoa(data->move_count);
  if (!moves)
    return;
  mlx_string_put(data->mlx, data->wnd, (data->col * IMG_PXL) - 140, 30,
                 0xFFFFFF, "Moves: ");
  mlx_string_put(data->mlx, data->wnd, (data->col * IMG_PXL) - 80, 30, 0xFFFFFF,
                 moves);
  free(moves);
}
