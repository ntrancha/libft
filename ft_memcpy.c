/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:28:42 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/15 09:54:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_tmp;
	char	*src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
