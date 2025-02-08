/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:19 by juhanse           #+#    #+#             */
/*   Updated: 2025/02/08 14:19:38 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(char *s, int count)
{
	int	i;

	i = -1;
	while (s[++i])
		count += ft_putchar(s[i], count);
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n < 0)
	{
		count += ft_putchar('-', count);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10, count);
		count += ft_putnbr(n % 10, count);
	}
	else
		count += ft_putchar(n + '0', count);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'd')
				count += ft_putnbr(va_arg(args, int), count);
			else if (s[i + 1] == 's')
				count += ft_putstr(va_arg(args, char *), count);
			i++;
		}
		else
			count += ft_putchar(s[i], count);
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("%d\n", ft_printf("Hello %s | %d\n", "world", 42));
// 	return (0);
// }
