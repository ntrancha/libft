/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitscreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:36:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 06:38:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/bits.h"

t_bits		*ft_bitscreate(void *memory, size_t octet)
{
	t_bits	*mem;

	mem = ft_memalloc(sizeof(t_bits));
	if (!mem)
		return (NULL);
	if (!memory)
	{
		mem->memory = NULL;
		mem->octet = 0;
	}
	else
	{
		mem->memory = ft_memalloc(octet + 1);
	   	ft_memcpy(mem->memory, memory, octet);
		mem->memory[octet] = 0;
		mem->octet = octet;
	}
	return (mem);
}
