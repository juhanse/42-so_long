/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/11 15:44:27 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
}	t_map;

// UTILS
int		ft_isalnum(int c);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_printf(const char *s, ...);

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_gnl
{
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

typedef struct t_stack
{
	t_gnl	*top;
	int		size;
}	t_stack;

void	deallocate(t_stack *list, t_gnl *new_node, char *buffer);
void	add_stack(t_stack *stack, char *buffer);
char	*ft_strcpy(char *str, t_stack *stack);
void	create(t_stack *list, int fd);
char	*get_da_line(t_stack *stack);
void	next_call(t_stack *stack);
char	*get_next_line(int fd);
int		len_to_ln(t_stack *stack);
int		new_line(t_stack *stack);
char	*extract_after_newline(t_stack *stack);

// SO_LONG - MAP
void	ft_init_map(t_map *map, char *map_path);
void	ft_check_path(t_map *map);
int		ft_count_items(t_map *map, char type);
void	ft_parse_map(t_map *map);
void	ft_free_map(t_map *map);
void	ft_check_dimensions(t_map *map);
void	ft_allocate_map(t_map *map);
void	ft_fill_map(t_map *map);
// SO_LONG - GAME
void	ft_hooks(t_map *map);
void	load_img(t_map *map, char *path, int index);
void	fill_game(t_map *map);
void	start_game(t_map *map);
void	refresh_game(t_map *map);
int		quit_game(t_map *map);
void	finish_game(t_map *map);
// SO_LONG - MOVE
int		key_hook(int keycode, t_map *map);
int		ft_move(t_map *map, int axe, int pos);
// SO_LONG - FLOOD FILL
void	ft_free_copy(t_map *map);
void	ft_copy_map(t_map *map);
void	flood_fill(t_map *map, int x, int y, int *collects);
void	ft_map_reachable(t_map *map);

#endif
