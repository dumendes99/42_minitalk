/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:45:52 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:46:00 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	s_flags;

	init_struct(&s_flags);
	va_start(args, str);
	while (str[s_flags.index] != '\0')
	{
		if (str[s_flags.index] == '%')
		{
			s_flags.index++;
			ft_check_sign((char *)str, &s_flags);
			ft_check_width((char *)str, &s_flags, args);
			ft_result_flags(&s_flags);
			ft_parse_args((char *)str, &s_flags, args);
			ft_reset_flags(&s_flags);
		}
		else
			ft_putchar_fd(str[s_flags.index], 1, &s_flags);
		s_flags.index++;
	}
	va_end(args);
	return (s_flags.size);
}
