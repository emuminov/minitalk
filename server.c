/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:05 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/23 19:35:48 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigusr(int sig)
{
	static char	c;
	static int	curr_bit;

	if (sig == SIGUSR1)
	{
		c |= 1 << (7 - curr_bit);
		curr_bit++;
	}
	if (sig == SIGUSR2)
		curr_bit++;
	if (curr_bit == 8)
		printf("%c\n", c);
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
		usleep(1);
}
