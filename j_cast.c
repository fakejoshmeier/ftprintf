/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/28 16:51:38 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	j_int_cast(va_list arg)
{
	intmax_t	output;

	output = (intmax_t)va_arg(arg, void*);
	ft_putnbr(output);
}

void	j_oct_cast(va_list arg)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	ft_putunbr_base(output, 8);
}

void	j_hex_cast(va_list arg)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	ft_putunbr_base(output, 12);
}

void	j_lhex_cast(va_list arg)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	ft_putnbr_base_lc(output, 16, 1);
}

void	j_uint_cast(va_list arg)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	ft_putunbr_base(output, 10);
}
