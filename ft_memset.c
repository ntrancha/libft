/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:22:10 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/10 17:59:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = (char *)b;
	while (len--)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
