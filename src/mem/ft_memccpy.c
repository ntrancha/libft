/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:38:22 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:26:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*strs;
	char	*strd;
	int		count;

	if (!n)
		return (NULL);
	strs = (char *)src;
	strd = (char *)dst;
	count = 0;
	while (n)
	{
		strd[count] = strs[count];
		if (strs[count] == c)
			return (&strd[count + 1]);
		count++;
		n--;
	}
	return (NULL);
}
