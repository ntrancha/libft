/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 08:29:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 09:28:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
        ret += ft_octetgetbit(memory->memory[size], 7) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 6) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 5) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 4) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 3) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 2) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 1) * ft_power(2, c--);
        ret += ft_octetgetbit(memory->memory[size], 0) * ft_power(2, c--);
    }
    return (ret);
}
