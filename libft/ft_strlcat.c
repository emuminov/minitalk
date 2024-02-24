/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:46:47 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/13 03:00:46 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size > dst_l)
	{
		while (src[i] && i < size - dst_l - 1)
		{
			dst[dst_l + i] = src[i];
			i++;
		}
		dst[dst_l + i] = '\0';
	}
	if (size > dst_l)
		return (dst_l + src_l);
	return (size + src_l);
}
