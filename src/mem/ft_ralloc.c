/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ralloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:08:57 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:35:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/mem.h"

void	    *ft_ralloc(void *ptr, size_t size_of, size_t new_size)
{
	void    *new;

	if (!ptr && size_of <= new_size)
		return (ptr);
	new = ft_memalloc(new_size);
	if (new)
	{
		ft_memcpy(new, ptr, new_size);
		ft_memdel(&ptr);
	}
	return (new);
}
