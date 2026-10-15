/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:21:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 18:04:44 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int ft_load_img(t_data *data, char *path, int index) {
  if (!path || data->assets[index].img)
    return (perror("Error\nFailed load image\n"), ft_free_map(data), 0);
  data->assets[index].path = path;
  data->assets[index].width = IMG_PXL;
  data->assets[index].height = IMG_PXL;
  data->assets[index].img = mlx_xpm_file_to_image(
      data->mlx, path, &data->assets[index].width, &data->assets[index].height);
  if (!data->assets[index].img)
    return (perror("Error\nFailed load image\n"), ft_free_map(data), 0);
  return (1);
}

static void ft_render_tile(t_data *data, int i, int j) {
  if (data->map[i][j] != '1')
    mlx_put_image_to_window(data->mlx, data->wnd, data->assets[ASSET_FLOOR].img,
                            j * IMG_PXL, i * IMG_PXL);
  if (data->map[i][j] == '1')
    mlx_put_image_to_window(data->mlx, data->wnd, data->assets[ASSET_WALL].img,
                            j * IMG_PXL, i * IMG_PXL);
  else if (data->map[i][j] == 'C')
    mlx_put_image_to_window(data->mlx, data->wnd,
                            data->assets[ASSET_ITEM + data->item_frame].img,
                            j * IMG_PXL, i * IMG_PXL);
  else if (data->map[i][j] == 'E')
    mlx_put_image_to_window(data->mlx, data->wnd, data->assets[ASSET_EXIT].img,
                            j * IMG_PXL, i * IMG_PXL);
}

void ft_fill_game(t_data *data) {
  int i;
  int j;

  i = -1;
  while (++i < data->line) {
    j = -1;
    while (++j < data->col)
      ft_render_tile(data, i, j);
  }
  if (data->enemy.exists)
    mlx_put_image_to_window(data->mlx, data->wnd,
                            data->assets[ASSET_ENEMY].img,
                            data->enemy.x * IMG_PXL, data->enemy.y * IMG_PXL);
  mlx_put_image_to_window(data->mlx, data->wnd,
                          data->assets[ASSET_PLAYER + data->player_frame].img,
                          data->player.x * IMG_PXL, data->player.y * IMG_PXL);
  ft_display_moves(data);
}

int ft_quit_game(t_data *data) {
  int i;

  i = -1;
  while (++i < ASSET_COUNT) {
    if (data->assets[i].img)
      mlx_destroy_image(data->mlx, data->assets[i].img);
  }
  mlx_destroy_window(data->mlx, data->wnd);
  ft_free_map(data);
  ft_printf("Leave game\n");
  exit(EXIT_SUCCESS);
  return (0);
}

int ft_start_game(t_data *data) {
  if (!ft_load_img(data, "./assets/floor.xpm", ASSET_FLOOR) ||
      !ft_load_img(data, "./assets/wall.xpm", ASSET_WALL) ||
      !ft_load_img(data, "./assets/exit.xpm", ASSET_EXIT) ||
      !ft_load_img(data, "./assets/player/player1.xpm", ASSET_PLAYER) ||
      !ft_load_img(data, "./assets/player/player2.xpm", ASSET_PLAYER + 1) ||
      !ft_load_img(data, "./assets/player/player3.xpm", ASSET_PLAYER + 2) ||
      !ft_load_img(data, "./assets/player/player4.xpm", ASSET_PLAYER + 3) ||
      !ft_load_img(data, "./assets/player/player5.xpm", ASSET_PLAYER + 4) ||
      !ft_load_img(data, "./assets/item/item1.xpm", ASSET_ITEM) ||
      !ft_load_img(data, "./assets/item/item2.xpm", ASSET_ITEM + 1) ||
      !ft_load_img(data, "./assets/attack.xpm", ASSET_ENEMY))
    return (0);
  ft_fill_game(data);
  ft_hooks(data);
  return (1);
}
