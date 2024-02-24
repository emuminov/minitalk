/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:05 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/24 16:00:00 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

typedef struct s_server_state
{
	int		size;
	int		size_received;
	char	*message;
	int		message_received;
}	t_server_state;

void	receive_size(int signal, t_server_state *state)
{
	static int	curr_bit;

	if (signal == SIGUSR1)
	{
		state->size |= 1 << (sizeof(int) * 8 - 1 - curr_bit);
		curr_bit++;
	}
	if (signal == SIGUSR2)
		curr_bit++;
	if (curr_bit == sizeof(int) * 8)
	{
		state->size_received = 1;
		curr_bit = 0;
	}
}

void	handle_cleanup(int *i, int *curr_bit, char *c, t_server_state *state)
{
	state->message[*i] = '\0';
	write(1, state->message, state->size);
	write(1, "\n", 1);
	state->message_received = 1;
	state->size = 0;
	state->size_received = 0;
	*i = 0;
	*curr_bit = 0;
	*c = 0;
}

void	receive_message(int signal, t_server_state *state)
{
	static int	curr_bit;
	static char	c;
	static int	i;

	if (signal == SIGUSR1)
	{
		c |= 1 << (sizeof(char) * 8 - 1 - curr_bit);
		curr_bit++;
	}
	else if (signal == SIGUSR2)
		curr_bit++;
	if (curr_bit == sizeof(char) * 8 && c)
	{
		state->message[i] = c;
		i++;
		curr_bit = 0;
		c = 0;
	}
	else if (curr_bit == sizeof(char) * 8 && !c)
		handle_cleanup(&i, &curr_bit, &c, state);
}

void	handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	static t_server_state	state;

	(void)context;
	if (!state.size_received)
		receive_size(signal, &state);
	else
	{
		if (!state.message)
			state.message = malloc((sizeof(char) + 1) * state.size);
		receive_message(signal, &state);
	}
	if ((signal == SIGUSR1 || signal == SIGUSR2) && !state.message_received)
		kill(siginfo->si_pid, SIGUSR1);
	else if (state.message_received)
	{
		state.message_received = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		usleep(1);
}
