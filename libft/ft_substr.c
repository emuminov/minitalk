/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:43:12 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/16 17:02:38 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// added len check
// hola\0 4
// ..la\0 2
//        3
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start > l)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	if (len + start > l)
		len = l - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[start + i] && (start + i) < (start + len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
