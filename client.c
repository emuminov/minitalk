/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:02 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 15:09:58 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void	send_bit(int bit_index, int bits_number, int c, int pid)
{
	if (c & 1 << (bits_number - 1 - bit_index))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_size(int pid, int size, int *size_sent)
{
	static int	curr_bit;
	static int	message_size;

	if (!message_size && size)
		message_size = size;
	send_bit(curr_bit++, sizeof(int) * 8, message_size, pid);
	if (curr_bit == sizeof(int) * 8)
	{
		curr_bit = 0;
		*size_sent = 1;
		return ;
	}
	usleep(1);
}

void	send_message(int pid, int *size_sent, char *str)
{
	static int	i;
	static int	curr_bit;
	static char	*message = NULL;

	if (!message && str)
		message = str;
	if (!size_sent)
		return ;
	send_bit(curr_bit++, sizeof(char) * 8, message[i], pid);
	if (curr_bit == sizeof(char) * 8 && message[i])
	{
		curr_bit = 0;
		i++;
	}
	usleep(1);
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int	size_sent;

	(void)context;
	if (!size_sent && signal == SIGUSR1)
	{
		send_size(siginfo->si_pid, 0, &size_sent);
	}
	else if (size_sent && signal == SIGUSR1)
	{
		send_message(siginfo->si_pid, &size_sent, NULL);
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
	send_message(atoi(pid), NULL, str);
	send_size(atoi(pid), strlen(str), 0);
	while (1)
		pause();
}
