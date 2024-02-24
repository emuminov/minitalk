/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:05 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 08:55:18 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	curr_bit;

	(void)context;
	if (signal == SIGUSR1)
	{
		c |= 1 << (7 - curr_bit);
		curr_bit++;
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (signal == SIGUSR2)
	{
		curr_bit++;
		kill(siginfo->si_pid, SIGUSR1);
	}
	if (curr_bit == 8 && c)
	{
		write(1, &c, 1);
		curr_bit = 0;
		c = 0;
	}
	else if (curr_bit == 8 && !c)
	{
		write(1, "\n", 1);
		curr_bit = 0;
		c = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int 				pid;
	struct sigaction	sa;

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{}
}
