/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:05:55 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 22:05:29 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handler(int sig)
{
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
		ft_printf("%c", letter);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = 0;
	pid = getpid();
	ft_printf("process id: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
