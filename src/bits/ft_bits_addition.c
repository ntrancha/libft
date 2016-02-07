/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits_addition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:48:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 16:33:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bits.h"

static t_bits   *ft_bits_addition_neg(t_bits *a, t_bits *b, int base, int cmp)
{
    t_bits      *res;

    res = (B_GT_A) ? B_SUB_A : A_SUB_B;
    if (A_GT_B && cmp < 0)
        ft_bits_neg(res);
    if (B_GT_A && cmp > 0)
        ft_bits_neg(res);
    return (res);
}

static t_bits   *ft_bits_addition_add(t_bits *a, t_bits *b, int base)
{
    int         cmp;
    int         neg_a;
    int         neg_b;
    t_bits      *res;

    cmp = ft_bits_cmp(a, b);
    neg_a = ft_bits_isneg(a);
    neg_b = ft_bits_isneg(b);
    BITS_ABS(a);
    BITS_ABS(b);
    if (!neg_a && !neg_b)
        res = A_ADD_B;
    else if (neg_a && neg_b)
        res = BITS_NEG(A_ADD_B);
    else
        res = ft_bits_addition_neg(a, b, base, cmp);
    if (neg_a)
        BITS_NEG(a);
    if (neg_b)
        BITS_NEG(b);
    return (res);
}

static t_bits   *ft_bits_addition_sub(t_bits *a, t_bits *b, int base)
{
    int         neg_a;
    int         neg_b;
    t_bits      *res;

    neg_a = ft_bits_isneg(a);
    neg_b = ft_bits_isneg(b);
    BITS_ABS(a);
    BITS_ABS(b);
    if ((neg_a && !neg_b) || (!neg_a && neg_b))
        res = (neg_b) ? A_ADD_B : BITS_NEG(A_ADD_B);
    else
    {
        res = (B_GT_A) ? B_SUB_A : A_SUB_B;
        if ((!neg_a && !neg_b && B_GT_A) || (neg_a && neg_b && A_GT_B))
            res = ft_bits_neg(res);
    }
    if (neg_b)
        ft_bits_neg(b);
    if (neg_a)
        ft_bits_neg(a);
    return (res);
}

t_bits          *ft_bits_addition(t_bits *a, t_bits *b, int base, int sign)
{
    t_bits      *res;

    if (sign >= 0)
        res = ft_bits_addition_add(a, b, base);
    else
        res = ft_bits_addition_sub(a, b, base);
    return (res);
}
