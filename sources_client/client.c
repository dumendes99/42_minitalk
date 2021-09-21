/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:50:02 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:17:20 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	get_char(int pid, unsigned int c)
{
	int count;
	char bin[9];
	int i = 7;

	count = 0;
	bin[8] = '\0';
	while (count < 8)
	{
		if (c % 2 == 0 || c == 0)
		{
			kill(pid, SIGUSR1);
			sleep(1);
			bin[i] = '0';
		}
		else
		{
			kill(pid, SIGUSR2);
			sleep(1);
			bin[i] = '1';
		}
		c /= 2;
		printf("count client == %d\n", count);
		count++;
		i--;
	}
	// printf("%s\n", bin);
}

int	get_id(char *arg)
{
	int id;

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

int main(int argc, char *argv[])
{	
	pid_t pid;
	
	if (argc != 3)
	{
		ft_printf("Please inform PID, and the string wich you want send!\n");
		return (0);
	}
	pid = get_id(argv[1]);
	ft_printf("%d\n", pid);
	if (!pid)
		ft_printf("Please inform a correct PID!!\n");
	while(*argv[2])
	{
		get_char(pid, *argv[2]);
		ft_printf("%c\n", *argv[2]);
		argv[2]++;
	}
	ft_printf("\n");
	return (1);
}
