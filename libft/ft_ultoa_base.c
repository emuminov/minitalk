/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:51:46 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 16:51:56 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits_base_ul(unsigned long n, size_t base_l)
{
	int			d;

	d = (n == 0);
	while (n > 0)
	{
		n /= base_l;
		d++;
	}
	return (d);
}

char	*ft_ultoa_base(const char *base, unsigned long n)
{
	int				d;
	size_t			base_l;
	char			*str;

	base_l = ft_strlen(base);
	if (!base_l)
		return (0);
	d = ft_count_digits_base_ul(n, base_l);
	str = malloc(sizeof(char) * (d + 1));
	if (!str)
		return (0);
	str[d] = '\0';
	while (d--)
	{
		str[d] = base[(n % base_l)];
		n /= base_l;
	}
	return (str);
}
