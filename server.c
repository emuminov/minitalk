/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:05 by emuminov          #+#    #+#             */
/*   Updated: 2024/02/22 15:32:41 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("1\n");
}

void	handle_sigusr2(int sig)
{
	(void)sig;
	printf("0\n");
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
	{
		sleep(1);
	}
}
