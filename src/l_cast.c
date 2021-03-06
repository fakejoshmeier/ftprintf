/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/18 16:51:32 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_int_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	long			output;

	output = (long)va_arg(arg, void*);
	prefix = sign_prefix_parse((int)output, f);
	prec_pad = sign_prec_parse(output, f);
	width_pad = sign_width_parse(output, f);
	if (f->dash == 1)
	{
		ft_putstr(prec_pad);
		ft_ld((long)output);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_ld((long)output);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	l_oct_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	prec_pad = prec_parse(output, f, 8);
	width_pad = width_parse(output, f, 8);
	prefix = prefix_parse((unsigned int)output, 8, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putoct((unsigned long)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_putoct((unsigned long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	l_hex_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	prec_pad = prec_parse((unsigned long)output, f, 16);
	width_pad = width_parse((unsigned long)output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 1, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_puthex((unsigned long)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_puthex((unsigned long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	l_lhex_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	prec_pad = prec_parse((unsigned long long)output, f, 16);
	width_pad = width_parse((unsigned long long)output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putlhex((unsigned long)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putlhex((unsigned long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	l_uint_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	prec_pad = prec_parse((unsigned long)output, f, 10);
	width_pad = width_parse((unsigned long)output, f, 10);
	prefix = prefix_parse((unsigned int)output, 10, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putull((unsigned long long)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putull((unsigned long long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}
