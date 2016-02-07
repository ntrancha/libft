/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octetsetbit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:42:19 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:48:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

t_octet	ft_octetsetbit(t_octet a, int bit, int value)
{
	bit %= 8;
	if (value == 0)
		a &= ~(1 << bit);
	else
		a |= (1 << bit);
	return (a);
}
