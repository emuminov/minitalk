/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:36:59 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/21 13:44:44 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *base, const char *str)
{
	long	result;
	short	sign;
	size_t	i;
	size_t	base_l;
	char	*base_digit;

	result = 0;
	base_l = ft_strlen(base);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ((str[i] == '-') * -1) + ((str[i] != '-') * 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	base_digit = ft_strchr(base, (int) str[i]);
	while (str[i] && base_digit)
	{
		result = (result * base_l) + (base_digit - base);
		base_digit = ft_strchr(base, (int) str[++i]);
	}
	return (result * sign);
}
