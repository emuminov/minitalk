/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:30:47 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/21 22:33:02 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long long	result;
	short		sign;
	size_t		i;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ((str[i] == '-') * -1) + ((str[i] != '-') * 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
