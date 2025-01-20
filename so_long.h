/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 12:48:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

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

typedef struct	s_player
{
	int	x;
	int	y;
} t_player;

typedef struct	s_end
{
	int	x;
	int	y;
} t_end;

typedef struct	s_map
{
	char		*filename;
	int			y;
	int			x;
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
} t_map;

void	ft_initialize(t_map *map, char **av);
int		ft_parse_map(char *map);

#endif
