/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hashtag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:46:08 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:46:10 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_hashtag(char *str, t_flags *s_flags)
{
	if (str[s_flags->index] == '#')
	{
		s_flags->hashtag = 1;
		s_flags->index++;
	}
}

void	print_hashtag(char *str, t_flags *s_flags)
{
	if (s_flags->hashtag && s_flags->num != 0)
	{
		if (str[s_flags->index] == 'x')
			ft_putstr("0x", 1, s_flags);
		else
			ft_putstr("0X", 1, s_flags);
	}
}
