/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitscreate_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 08:05:43 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 08:09:29 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/bits.h"

t_bits		*ft_bitscreate_empty(size_t octet)
{
	t_bits	*mem;

	mem = ft_memalloc(sizeof(t_bits));
	if (!mem)
		return (NULL);
	mem->memory = ft_memalloc(octet + 1);
	mem->memory[octet] = 0;
	mem->octet = octet;
	return (mem);
}

