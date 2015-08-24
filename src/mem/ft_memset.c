/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:22:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:30:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
