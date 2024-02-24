/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:50:50 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/22 23:24:25 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	short	sign;
	size_t	i;

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
