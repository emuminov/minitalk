/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:06:20 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/14 22:52:26 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	else if (dest > src && (size_t)(dest - src) < n)
	{
		i = n - 1;
		while ((long long) i >= 0)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
