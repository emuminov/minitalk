/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:32:35 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/07 13:00:18 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putbadflag(char flag)
{
	ft_putchar_fd('%', 1);
	ft_putchar_fd(flag, 1);
	return (2);
}

static int	ft_format(char flag, va_list args)
{
	int	count;

	count = 1;
	if (flag == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (flag == 's')
		count = ft_putstr_arg(args);
	else if (flag == 'd' || flag == 'i')
		count = ft_putnbr(args);
	else if (flag == 'u')
		count = ft_putnbr_unsigned(args);
	else if (flag == 'p')
		count = ft_puthex_ptr(args);
	else if (flag == 'x')
		count = ft_puthex_ui(0, args);
	else if (flag == 'X')
		count = ft_puthex_ui(1, args);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
	else
		count = ft_putbadflag(flag);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_format(str[i++ + 1], args);
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
