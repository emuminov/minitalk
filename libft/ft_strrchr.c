/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:33:37 by emuminov          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:59 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	if ((char) c == '\0')
		return ((char *) &(s[ft_strlen(s)]));
	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *) &s[i];
		i++;
	}
	return (last);
}
