/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsgetaddr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:41:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:44:01 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/bits.h"

static size_t   ft42_strlen(const char *str)
{
	size_t	    count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

t_octet		*ft_bitsgetaddr(t_bits *memory, int octet)
{
	if (octet < (int)ft42_strlen((char*)memory->memory))
		return (&memory->memory[octet]);
	return (0);
}
