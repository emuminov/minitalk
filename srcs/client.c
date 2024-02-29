/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:02 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/29 12:38:18 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>

void	send_bit(int bit_index, int bits_number, int c, int pid)
{
	if (c & 1 << (bits_number - 1 - bit_index))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	send_size(int pid, int init_size, int *size_sent)
{
	static int	curr_bit;
	static int	message_size;

	if (!message_size && init_size)
		message_size = init_size;
	send_bit(curr_bit++, INT_BITS, message_size, pid);
	if (curr_bit == INT_BITS)
	{
		curr_bit = 0;
		*size_sent = 1;
		return ;
	}
}

void	send_message(int pid, int *size_sent, char *init_message)
{
	static int	i;
	static int	curr_bit;
	static char	*message;

	if (!message && init_message)
		message = init_message;
	if (!size_sent)
		return ;
	send_bit(curr_bit++, CHAR_BITS, message[i], pid);
	if (curr_bit == CHAR_BITS && message[i])
	{
		curr_bit = 0;
		i++;
	}
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static int	size_sent;

	(void)context;
	if (!size_sent && signal == SIGUSR1)
		send_size(siginfo->si_pid, 0, &size_sent);
	else if (size_sent && signal == SIGUSR1)
		send_message(siginfo->si_pid, &size_sent, NULL);
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
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pid = argv[1];
	if (ft_atoi(pid) < 1)
	{
		ft_putstr_fd("Bad pid\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	str = argv[2];
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	send_message(ft_atoi(pid), NULL, str);
	send_size(ft_atoi(pid), ft_strlen(str), 0);
	while (1)
		pause();
}
