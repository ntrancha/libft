/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitssetbit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:42:19 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 06:42:40 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

int			ft_bitssetbit(t_bits *memory, int octet, int bit, int value)
{
	if (ft_bitsgetoctet(memory, octet) == 0 || bit > 7)
		return (-1);
	if (value == 0)
		memory->memory[octet] &= ~(1 << bit);
	else
		memory->memory[octet] |= (1 << bit);
	return (value);
}
