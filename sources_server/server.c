/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:05:55 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:22:29 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void handler(int sig)
{
	static unsigned int	count;
	static unsigned int letter;

	ft_printf("count server == %d\n", count);
	// ft_printf("letter == %d\n", letter);
	if (count > 7)
	{
		count = 0;
		letter = 0;
	}
	if (sig == SIGUSR2)
	{
		letter += 1 << count;
		// ft_printf("1\n");
	}
	if (sig == SIGUSR1)
		// ft_printf("0\n");
	count++;
	// if (count == 8)
		// ft_printf("%d", letter);
}

int main(void)
{
	int pid;
	struct sigaction sa;

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

// o binario vai chegar aqui, tenho que colocar ele dentro de uma variavel static para poder mecher na estrutura binaria dela sempre que entrar nessa função. 
// tenho que ter outra variavel static para saber que fui até 8;