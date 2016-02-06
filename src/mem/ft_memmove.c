/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:46:38 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:08:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	char			*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (pdst <= psrc || pdst >= (psrc + len))
	{
		while (psrc && pdst && len--)
			*pdst++ = *psrc++;
	}
	else
	{
		pdst += len - 1;
		psrc += len - 1;
		while (psrc && pdst && len--)
			*pdst-- = *psrc--;
	}
	return (dst);
}
