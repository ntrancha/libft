/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:48:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/26 13:33:03 by ntrancha         ###   ########.fr       */
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

static int      ft_bits_addition_cmp(t_bits *a, t_bits *b);

static int      ft_bitscmp_neg(t_bits *a, t_bits *b)
{
    int         ret;

    if (b->memory[0] == 255 && a->memory[0] != 255)
        return (1);
    if (a->memory[0] == 255 && b->memory[0] != 255)
        return (-1);
    a->memory[0] = 0;
    b->memory[0] = 0;
    ret = ft_bits_addition_cmp(b, a);
    a->memory[0] = 255;
    b->memory[0] = 255;
    return (ret);
}

static int      ft_bits_addition_cmp(t_bits *a, t_bits *b)
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
        if (tmp_a >= 0 && tmp_b >= 0)
        {
            if (a->memory[tmp_a] > b->memory[tmp_b])
                return (1);
            if (b->memory[tmp_b] > a->memory[tmp_a])
                return (-1);
        }
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
    ft_putnbr_endl(ft_bits_addition_cmp(a, b));
    //ft_bits_addition_abs2(a);
    //ft_bits_addition_neg(b);
    ft_bitsdel(tmp_a);
    ft_bitsdel(tmp_b);
    ft_itof(base);
    ft_itof(sign);
    return (a);
}
