/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:46:27 by elima-me          #+#    #+#             */
/*   Updated: 2021/09/20 21:46:29 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_flags *s_flags)
{
	s_flags->minus = 0;
	s_flags->zero = 0;
	s_flags->width = 0;
	s_flags->hashtag = 0;
	s_flags->index = 0;
	s_flags->size = 0;
	s_flags->plus = 0;
	s_flags->space = 0;
	s_flags->num = 0;
}

void	ft_reset_flags(t_flags *s_flags)
{
	s_flags->minus = 0;
	s_flags->zero = 0;
	s_flags->width = 0;
	s_flags->hashtag = 0;
	s_flags->plus = 0;
	s_flags->space = 0;
	s_flags->num = 0;
}
