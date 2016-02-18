/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 07:57:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 05:52:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"
#include "../../includes/mem.h"

static void     ft_putintvoid(void *str)
{
    int         *num;

    num = (int*)(str);
    ft_putnbr(*num);
}

static void     *ft_intcpyvoid(void *src, void *dst)
{
    t_alloc     *alloc;

    alloc = ft_alloc_get(src);
    return (ft_sysint_alloc(*((int*)alloc->content), dst));
}

static int      ft_intlenvoid(void *a)
{
    int         *num;

    num = (int*)a;
    return ((int)ft_nbrlen((int)*num));
}

static int      ft_intcmpvoid(void *a, void *b)
{
    int         *int_a;
    int         *int_b;

    int_a = (int*)a;
    int_b = (int*)b;
    if (*int_a > *int_b)
        return (1);
    if (*int_a < *int_b)
        return (-1);
    return (0);
}

void            ft_sysint(void)
{
    t_type  *type;

    type = ft_vartype_add("int", sizeof(int), ft_memdel); 
    while (type && type->next)
        type = type->next;
    type->put = ft_putintvoid; 
    type->cpy = ft_intcpyvoid; 
    type->len = ft_intlenvoid; 
    type->cmp = ft_intcmpvoid; 
}
