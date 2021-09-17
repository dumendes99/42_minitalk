/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:50:02 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/17 13:35:15 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Please inform PID, and the string witch you want send!\n");
		return (0);
	}
	printf("%s\n", argv[1]);
	return (1);
}
