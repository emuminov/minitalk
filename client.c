/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:02 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 08:56:53 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_bit(int bit_index, int c, int pid)
{
	if (c & 1 << (7 - bit_index))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send(int pid, char *str)
{
	static int	i;
	static int	curr_bit;
	static char	*message = NULL;

	if (!message && str)
		message = str;
	send_bit(curr_bit++, message[i], pid);
	usleep(300);
	if (curr_bit == 8 && message[i])
	{
		curr_bit = 0;
		i++;
	}
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signal == SIGUSR1)
	{
		send(siginfo->si_pid, NULL);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "OK!\n", 4);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	char				*pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
		return (EXIT_FAILURE);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	pid = argv[1];
	str = argv[2];
	send(atoi(pid), str);

	pause();
}
