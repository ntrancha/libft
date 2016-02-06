/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 04:22:57 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 11:09:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int      ft_bits_cmp(t_bits *a, t_bits *b);

static int      ft_bitscmp_neg(t_bits *a, t_bits *b)
{
    int         ret;

    if (b->memory[0] == 255 && a->memory[0] != 255)
        return (1);
    if (a->memory[0] == 255 && b->memory[0] != 255)
        return (-1);
    a->memory[0] = 0;
    b->memory[0] = 0;
    ret = ft_bits_cmp(b, a);
    a->memory[0] = 255;
    b->memory[0] = 255;
    return (ret);
}

int      ft_bits_cmp(t_bits *a, t_bits *b)
{
    int         count;
    int         size;
    int         tmp_a;
    int         tmp_b;

    if (a->memory[0] == 255 || b->memory[0] == 255)
        return (ft_bitscmp_neg(a, b));
    size = (a->octet > b->octet) ? a->octet : b->octet;
    count = -1;
    while (++count < size)
    {
        tmp_a = (a->octet - size + count);
        tmp_b = (b->octet - size + count);
        if (tmp_a < 0 && b->memory[tmp_b] != 0)
            return (-1);
        if (tmp_b < 0 && a->memory[tmp_a] != 0)
            return (1);
        while (tmp_a >= 0 && tmp_b >= 0)
            if (a->memory[tmp_a] > b->memory[tmp_b])
                return (1);
            else if (b->memory[tmp_b] > a->memory[tmp_a])
                return (-1);
    }
    return (0);
}
