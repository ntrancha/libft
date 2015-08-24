/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:37:03 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:59:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char				*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n && src[count] && src && dst)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < n && dst && src)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
