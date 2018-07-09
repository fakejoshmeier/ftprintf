/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:48:22 by jmeier            #+#    #+#             */
/*   Updated: 2018/07/08 20:17:59 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new;

	new = (void *)ft_memalloc(new_size);
	if (new == NULL)
		return (NULL);
	if (ptr == NULL)
		return (new);
	new = ft_memcpy(new, ptr, new_size);
	free(ptr);
	ptr = NULL;
	return (new);
}
