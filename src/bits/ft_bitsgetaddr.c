/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsgetaddr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:41:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 06:48:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/bits.h"

t_octet		*ft_bitsgetaddr(t_bits *memory, int octet)
{
	if (octet < (int)ft_strlen((char*)memory->memory))
		return (&memory->memory[octet]);
	return (0);
}
