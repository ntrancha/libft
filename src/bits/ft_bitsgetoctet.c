/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsgetoctet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:39:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 03:53:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/bits.h"

t_octet   ft_bitsgetoctet(t_bits *memory, int octet)
{
	if (octet < (int)memory->octet)
		return (memory->memory[octet]);
	return (0);
}
