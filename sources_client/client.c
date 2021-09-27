/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:50:02 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/27 12:02:02 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void handle_client(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("finished recieve signals\n");
		exit(0);
	}
}

void	get_char(int pid, unsigned char c)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		if (c % 2 == 0 || c == 0)
		{
			kill(pid, SIGUSR1);
			usleep(500);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(500);
		}
		c /= 2;
		count++;
	}
}

int	get_id(char *arg)
{
	int	id;

	id = 0;
	while (*arg)
	{
		if (*arg >= '0' && *arg <= '9')
			id = (id * 10) + (*arg - '0');
		else
			return (0);
		arg++;
	}
	return (id);
}

int	main(int argc, char *argv[])
{	
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Please inform PID, and the string wich you want send!\n");
		return (0);
	}
	pid = get_id(argv[1]);
	ft_printf("%d\n", pid);
	if (!pid)
		ft_printf("Please inform a correct PID!!\n");
	while (*argv[2])
	{
		get_char(pid, *argv[2]);
		argv[2]++;
	}
	signal(SIGUSR2, handle_client);
	get_char(pid, '\0');
	return (1);
}
