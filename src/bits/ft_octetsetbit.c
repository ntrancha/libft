/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octetsetbit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 06:42:19 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/11 11:00:53 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

int			ft_octetsetbit(t_octet a, int bit, int value)
{
	bit %= 7;
	if (value == 0)
		a &= ~(1 << bit);
	else
		a |= (1 << bit);
	return (value);
}
