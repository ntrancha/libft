/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:48:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 11:58:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void     ft_bits_addition_abs(t_bits *mem)
{
    if (mem->memory[0] == 255)
        mem->memory[0] = 0;
}

t_bits   *ft_bits_addition_abs2(t_bits *mem)
{
    t_bits      *new;

    new = ft_bitscopy(mem);
    ft_bits_addition_abs(new);
    return (new);
}

void     ft_bits_addition_neg(t_bits *mem)
{
    if (mem->memory[0] == 0)
        mem->memory[0] = 255;
}

static int      ft_bits_addition_cmp(t_bits *a, t_bits *b)
{
    int         count;

    if (a->octet > b->octet)
        return (1);
    else if (b->octet > a->octet)
        return (-1);
    count = -1;
    while (++count < (int)a->octet)
    {
        if (a->memory[count] > b->memory[count])
            return (1);
        if (b->memory[count] > a->memory[count])
            return (-1);
    }
    return (0);
}

static t_bits  *ft_bits_addzero(t_bits *mem, int zero)
{
    t_bits      *new;
    int         count;

    count = 0;
    new = ft_bitscreate_empty((mem)->octet + zero);
    while (zero < (int)new->octet)
        new->memory[zero++] = (mem)->memory[count++];
    return (new);
}

t_bits          *ft_bits_addition(t_bits *a, t_bits *b, int base, int sign)
{
    t_bits      *tmp_a;
    t_bits      *tmp_b;

    if (a->octet > b->octet)
    {
        tmp_a = ft_bitscopy(a);
        tmp_b = ft_bits_addzero(b, a->octet - b->octet);
    }
    if (a->octet < b->octet)
    {
        tmp_a = ft_bits_addzero(a, b->octet - a->octet);
        tmp_b = ft_bitscopy(b);
    }
    if (a->octet == b->octet)
    {
        tmp_a = ft_bitscopy(a);
        tmp_b = ft_bitscopy(b);
    }
    ft_putnbr_endl(ft_bits_addition_cmp(tmp_a, tmp_b));
    //ft_bits_addition_abs2(a);
    //ft_bits_addition_neg(b);
    ft_bitsdel(tmp_a);
    ft_bitsdel(tmp_b);
    ft_itof(base);
    ft_itof(sign);
    return (a);
}
