/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:02 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/22 15:51:42 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	// char	*pid;
	char	*str;
	int		i;
	int		j;

	if (argc != 3)
		return (EXIT_FAILURE);
	// pid = argv[1];
	str = argv[2];
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & (1 << (7 - j))))
				printf("1");
				// kill(atoi(pid), SIGUSR1);
			else
				// kill(atoi(pid), SIGUSR2);
				printf("0");
			j++;
		}
		i++;
	}
}

// 0110 0101

// 0110 0101
// 0000 0001         0000 0001
// 0000 0010         0000 0001
// 0000 0100         0000 0101
// 0000 1000         0000 0101
// 0001 0000         0000 0101
// 0010 0000         0010 0101
// 0100 0000         0110 0101
// 1000 0000         0000 0101

