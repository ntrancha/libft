/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:07:30 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/06 13:12:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(sizeof(char) * size);
	if (!size || !ptr)
		return (ptr);
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}
