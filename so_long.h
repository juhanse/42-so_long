/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/30 11:58:24 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define X 1730
# define Y 550
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define S 115
# define D 100
# define A 97
# define SPACE 32
# define ESC 65307
# define IMG_PXL 64
# define WND_NAME "so_long"

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

typedef struct s_map
{
	char		*map_path;
	char		**map;
	int			line;
	int			col;
	int			collects;
	int			exit;
	int			player_started;
	int			move_count;
	void		*mlx;
	void		*wnd;
	t_player	player;
	t_asset		assets[4];
}	t_map;

// UTILS
int		ft_isalnum(int c);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// GET_NEXT_LINE
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int character);
char	*ft_line_cat(char **s1, char *s2);
char	*get_next_line(int fd);

// SO_LONG - MAP
void	ft_init_struct(t_map *map, char *path);
void	ft_check_path(t_map *map);
void	ft_parse_map(t_map *map);
void	ft_free_map(t_map *map);
void	ft_read_map(t_map *map);
void	ft_allocate_map(t_map *map);
void	ft_fill_map(t_map *map);
// SO_LONG - MOVE
int		key_hook(int keycode, t_map *map);
void	ft_move(t_map *map, int axe, int pos);
// SO_LONG - GAME
void	load_img(t_map *map, char *path, int index);
void	fill_game(t_map *map);
void	start_game(t_map *map);
void	refresh_game(t_map *map);
int		quit_game(t_map *map);

#endif
