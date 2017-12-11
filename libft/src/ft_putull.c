/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:44:37 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 20:46:08 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putull(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putull(n / 10);
		ft_putull(n % 10);
	}
	else
		ft_putchar(n + '0');
}