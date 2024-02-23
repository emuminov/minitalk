/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:02 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/23 19:11:30 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*pid;
	char	*str;
	int		i;
	int		j;

	if (argc != 3)
		return (EXIT_FAILURE);
	pid = argv[1];
	str = argv[2];
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] & 1 << (7 - j))
				kill(atoi(pid), SIGUSR1);
			else
				kill(atoi(pid), SIGUSR2);
			usleep(1);
			j++;
		}
		i++;
	}
	pause();
}
