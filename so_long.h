/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/16 14:26:34 by juhanse          ###   ########.fr       */
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

typedef struct	v_map
{
	char	*filename;
} t_map;

typedef struct	v_player
{
	int	x;
	int	y;
} t_player;

typedef struct	s_end
{
	int	x;
	int	y;
} t_end;

#endif
