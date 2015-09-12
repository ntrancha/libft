/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:29:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 08:55:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long       ft_bitsvalue(t_bits *memory)
{
    int         size;
    int         count;
    int         bit;
    long long   ret;
    int         value;

    size = memory->octet;
    count = size * 8;
    ret = 0;
    ft_putnbr_endl(count);
    while ((int)size-- > 0)
    {
        ft_putoctet(memory->memory[size]);
        bit = 0;
        while (bit < 8)
        {
            value = ft_octetgetbit(memory->memory[size], bit++);
            ret += value * ft_power(2, count--);
        }
    }
    return (ret);
}
