/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:05:55 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/29 15:51:59 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handler(int sig, siginfo_t *sa, void *context)
{
	(void)context;
	static unsigned int	count;
	static unsigned int	letter;

	if (count > 7)
	{
		count = 0;
		letter = 0;
	}
	if (sig == SIGUSR2)
	{
		letter += 1 << count;
	}
	count++;
	if (count == 8)
	{
		if (letter == 0)
		{
			write(1, "\n", 1);
			kill(sa->si_pid, SIGUSR2);
		}
		else
			write(1, &letter, 1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("pid: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
