/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:29:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:46:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

static int      ft42_power(int nbr, int power)
{
    int         ret;

    ret = 1;
    if (power == 0)
		return (1);
	if (nbr == 0)
        return (0);
    if (power == 1)
        return (nbr);
    while (power-- > 0)
        ret *= nbr;
    return (ret);
}

long long       ft_bitsvalue(t_bits *memory)
{
    int         size;
    int         c;
    long long   ret;

    size = memory->octet;
    c = size * 8;
    ret = 0;
    while ((int)size-- > 0)
    {
        ret += ft_octetgetbit(memory->memory[size], 7) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 6) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 5) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 4) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 3) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 2) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 1) * ft42_power(2, --c);
        ret += ft_octetgetbit(memory->memory[size], 0) * ft42_power(2, --c);
    }
    return (ret);
}
