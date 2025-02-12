/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:45:45 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/12 17:46:04 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_line_len(char *s)
{
	int	len;

	if (s[ft_strlen(s) - 1] == '\n')
		len = ft_strlen(s) - 1;
	else
		len = ft_strlen(s);
	return (len);
}
