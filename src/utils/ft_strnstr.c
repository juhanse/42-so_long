/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:56:35 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/30 11:57:56 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < size)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	len_haystack;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (len > len_haystack)
		len = len_haystack;
	while (len >= len_needle)
	{
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
