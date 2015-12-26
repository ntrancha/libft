/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:48:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 10:51:01 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int  ft_bits_add_size(t_bits *a, t_bits *b)
{
    return ((a->octet > b->octet) ? a->octet : b->octet);
}

t_bits      *ft_bits_add(t_bits *a, t_bits *b, int base)
{
    int     res;
    int     ret;
    t_bits  *tmp;
    int     count;

    tmp = ft_bitscreate_empty(ft_bits_add_size(a, b) + 2);
    count = 0;
    ret = 0;
    while (++count <= ft_bits_add_size(a, b))
    {
        res = ret;
        ret = 0;
        if ((int)a->octet - count >= 0)
            res += ft_bitsgetoctet(a, (int)a->octet - count);
        if ((int)b->octet - count >= 0)
            res += ft_bitsgetoctet(b, (int)b->octet - count);
        if (res >= base && ++ret)
            res -= base;
        tmp->memory[ft_bits_add_size(a, b) - count + 2] = res;
    }
    tmp->memory[1] = ret;
    return (tmp);
}
