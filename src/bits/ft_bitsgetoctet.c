/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsgetoctet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:39:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 11:05:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/bits.h"

t_octet   ft_bitsgetoctet(t_bits *memory, int octet)
{
	if (octet < (int)ft_strlen((char*)memory->memory))
		return (memory->memory[octet]);
	return (0);
}
