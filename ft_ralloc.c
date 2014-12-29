/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ralloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:08:57 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 16:08:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_ralloc(void *ptr, size_t size_of, size_t new_size)
{
	t_uchar	*new;

	if (!ptr && size_of <= new_size)
		return (ptr);
	new = (t_uchar *)ft_memalloc(new_size);
	if (new)
	{
		ft_memcpy(new, ptr, new_size);
		ft_memdel(&ptr);
	}
	return (new);
}
