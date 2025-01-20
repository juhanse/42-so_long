/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:36:21 by juhanse           #+#    #+#             */
/*   Updated: 2025/01/20 21:56:30 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static char	*ft_stock_word(const char *str, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_add_word(char **buffer, const char *str, char c, int word)
{
	buffer[word] = ft_stock_word(str, c);
	if (!buffer[word])
		return (0);
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		word;
	char	**buffer;

	if (!str)
		return (NULL);
	buffer = (char **)malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && !ft_add_word(buffer, &str[i], c, word++))
			return (ft_free(buffer, word));
		while (str[i] && str[i] != c)
			i++;
	}
	buffer[word] = NULL;
	return (buffer);
}
