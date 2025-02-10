/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:32:46 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/10 12:37:13 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;
	int	len;

	if (!dst || !src)
		return (0);
	i = -1;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (len);
}
