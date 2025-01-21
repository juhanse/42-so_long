/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/21 14:23:21 by juhanse          ###   ########.fr       */
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

# define X 1000
# define Y 600
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53
# define IMG_PXL 64
# define WND_NAME "so_long"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		*map_path;
	char		**map;
	int			line;
	int			col;
	int			collects;
	int			exit;
	int			player_start;
	void		*mlx;
	void		*wnd;
	t_player	player;
}	t_map;

// UTILS
int		ft_isalnum(int c);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);

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
// SO_LONG - GAME
void	start_game(t_map *map);

#endif
