/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:11 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/11 17:14:20 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strchr_gnl(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] || c == '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	if (!src)
		return (NULL);
	i = -1;
	len = ft_strlen_gnl(src);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (++i < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i--;
	while (++i < len_s1 + len_s2)
		str[i] = s2[i - len_s1];
	str[i] = '\0';
	return (str);
}

// int	len_to_ln(t_stack *stack)
// {
// 	int		i;
// 	int		len;
// 	t_gnl	*current;

// 	if (stack == NULL)
// 		return (0);
// 	len = 0;
// 	current = stack->top;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (current->str[i])
// 		{
// 			if (current->str[i] == '\n')
// 			{
// 				len++;
// 				return (len);
// 			}
// 			i++;
// 			len++;
// 		}
// 		current = current->next;
// 	}
// 	return (len);
// }

// char	*ft_strcpy(char *str, t_stack *stack)
// {
// 	int		i;
// 	int		j;
// 	t_gnl	*current;

// 	j = 0;
// 	current = stack->top;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (current->str[i])
// 		{
// 			if (current->str[i] == '\n')
// 			{
// 				str[j++] = '\n';
// 				str[j] = '\0';
// 				break ;
// 			}
// 			str[j++] = current->str[i++];
// 		}
// 		current = current->next;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }

// void	deallocate(t_stack *list, t_gnl *new_node, char *buffer)
// {
// 	t_gnl	*temp;

// 	while (list->top != NULL)
// 	{
// 		temp = list->top->next;
// 		free(list->top->str);
// 		free(list->top);
// 		list->top = temp;
// 	}
// 	list->top = NULL;
// 	list->size = 0;
// 	if (new_node && new_node->str && new_node->str[0])
// 	{
// 		list->top = new_node;
// 		list->size = 1;
// 	}
// 	else
// 	{
// 		free(new_node);
// 		free(buffer);
// 	}
// }

// int	new_line(t_stack *stack)
// {
// 	int		i;
// 	t_gnl	*current;

// 	current = stack->top;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (current->str[i] && i < BUFFER_SIZE)
// 		{
// 			if (current->str[i] == '\n')
// 				return (1);
// 			i++;
// 		}
// 		current = current->next;
// 	}
// 	return (0);
// }

// char	*extract_after_newline(t_stack *stack)
// {
// 	char	*buffer;
// 	t_gnl	*last;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	last = stack->top;
// 	while (last && last->next != NULL)
// 		last = last->next;
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!last || !buffer)
// 		return (NULL);
// 	while (last->str[i] != '\n' && last->str[i] != '\0')
// 		i++;
// 	if (last->str[i] == '\n')
// 		i++;
// 	while (last->str[i] != '\0')
// 		buffer[j++] = last->str[i++];
// 	buffer[j] = '\0';
// 	return (buffer);
// }
