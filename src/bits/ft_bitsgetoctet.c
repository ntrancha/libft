/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsgetoctet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:39:54 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 09:43:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/bits.h"

t_bin   ft_bitsgetoctet(t_bits *memory, int octet)
{
	if (octet < (int)ft_strlen((char*)memory->memory))
		return (memory->memory[octet]);
	return (0);
}
