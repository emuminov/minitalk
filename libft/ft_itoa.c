/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:17:33 by emuminov          #+#    #+#             */
/*   Updated: 2023/12/07 01:07:37 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_digits(int n)
{
	int		d;

	if (n < 0)
		n = -n;
	d = (n == 0);
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int		d;
	short	is_neg;
	char	str[12];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	d = ft_count_digits(n);
	is_neg = (n < 0);
	if (is_neg)
	{
		str[0] = '-';
		n = -n;
	}
	str[d + is_neg] = '\0';
	while (d--)
	{
		str[d + is_neg] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strdup(str));
}
