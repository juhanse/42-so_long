/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 15:23:10 by juhanse          ###   ########.fr       */
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

typedef struct s_end
{
	int	x;
	int	y;
}	t_end;

typedef struct s_map
{
	char		*filename;
	char		**data;
	int			count_line;
	int			count_col;
	int			x;
	int			y;
	int			c;
	int			p;
	int			e;
	int			check_c;
	int			check_e;
	int			exit;
	int			move;
	void		*mlx;
	void		*wnd;
	t_player	player;
	t_end		end;
}	t_map;

// GET_NEXT_LINE
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int character);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_line_cat(char **s1, char *s2);
char	*get_next_line(int fd);

// SO_LONG
char	**ft_split(char const *str, char c);
int		ft_parse_map(char *map);
void	ft_free_map(char **map);
void	ft_initialize_map(char *map_path);

#endif
