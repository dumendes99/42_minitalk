/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:45:39 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:45:40 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign(char *str, t_flags *s_flags)
{
	while (str[s_flags->index] < '1' && (str[s_flags->index] != '%'))
	{
		if (str[s_flags->index] == '-')
		{	
			s_flags->minus = 1;
			s_flags->index++;
		}
		if (str[s_flags->index] == '0')
		{
			s_flags->zero = 1;
			s_flags->index++;
		}
		if (str[s_flags->index] == '+')
		{
			s_flags->plus = 1;
			s_flags->index++;
		}
		if (str[s_flags->index] == ' ')
		{
			s_flags->space = 1;
			s_flags->index++;
		}
		check_hashtag(str, s_flags);
	}
}

void	ft_result_flags(t_flags *s_flags)
{
	if ((s_flags->minus == 1) && s_flags->zero == 1)
		s_flags->zero = 0;
	if ((s_flags->plus == 1) && (s_flags->space == 1))
		s_flags->space = 0;
}

void	ft_check_width(char *str, t_flags *s_flags, va_list args)
{
	if (str[s_flags->index] == '*')
		s_flags->width = va_arg(args, int);
	if (str[s_flags->index] >= '0' && str[s_flags->index] <= '9')
		s_flags->width = ft_atoi(str, s_flags);
}
