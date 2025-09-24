/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/09/24 17:56:51 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define S 115
# define D 100
# define A 97
# define ESC 65307
# define IMG_PXL 64
# define WND_NAME "so_long - juhanse"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_asset
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_asset;

typedef struct s_data
{
	char		*map_path;
	char		**map;
	char		**copy;
	int			line;
	int			col;
	int			collects;
	int			move_count;
	int			exit_found;
	void		*mlx;
	void		*wnd;
	t_player	player;
	t_asset		assets[5];
}	t_data;

// UTILS
int		ft_isalnum(int c);
int		ft_strlen(char *s);
int		ft_line_len(char *s);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_printf(const char *s, ...);

// GET_NEXT_LINE
char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *s, char c);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup(const char *src);
int		get_len_line(char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

// SO_LONG - MAP
void	ft_free_map(t_data *data);
int		ft_initialization(t_data *data, char *map_path);
int		ft_check_path(t_data *data);
int		ft_count_items(t_data *data, char type);
int		ft_parse_map(t_data *data);
int		ft_check_dimensions(t_data *data);
int		ft_allocate_map(t_data *data);
int		ft_fill_map(t_data *data);

// SO_LONG - GAME
void	ft_hooks(t_data *data);
int		ft_load_img(t_data *data, char *path, int index);
void	ft_fill_game(t_data *data);
int		ft_start_game(t_data *data);
void	refresh_game(t_data *data);
int		quit_game(t_data *data);
void	finish_game(t_data *data);
// SO_LONG - MOVE
int		key_hook(int keycode, t_data *data);
int		ft_move(t_data *data, int axe, int pos);
// SO_LONG - FLOOD FILL
void	ft_flood_fill(t_data *data, int x, int y, int *collects);
int		ft_map_reachable(t_data *data);

#endif
