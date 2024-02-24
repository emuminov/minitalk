/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:18:24 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 16:47:36 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(va_list args)
{
	char	*str;
	size_t	l;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	l = ft_strlen(str);
	write(1, str, l);
	free(str);
	return (l);
}

int	ft_putnbr_unsigned(va_list args)
{
	size_t	l;
	char	*str;

	str = ft_ltoa_base("0123456789", va_arg(args, unsigned int));
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	l = ft_strlen(str);
	write(1, str, l);
	free(str);
	return (l);
}

int	ft_puthex_ptr(va_list args)
{
	size_t	l;
	void	*arg;
	char	*str;

	arg = va_arg(args, void *);
	if (!arg)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	str = ft_ultoa_base("0123456789abcdef", (unsigned long) arg);
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	l = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, l);
	free(str);
	return (l + 2);
}

int	ft_puthex_ui(int toupper, va_list args)
{
	size_t	i;
	char	*str;

	str = ft_ltoa_base("0123456789abcdef", va_arg(args, unsigned int));
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = 0;
	while (str[i])
	{
		if (toupper)
			str[i] = ft_toupper(str[i]);
		i++;
	}
	write(1, str, i);
	free(str);
	return (i);
}

int	ft_putstr_arg(va_list args)
{
	size_t		l;
	const char	*str;

	str = va_arg(args, const char *);
	if (!str)
		return (write(1, "(null)", 6));
	l = ft_strlen(str);
	write(1, str, l);
	return (l);
}
