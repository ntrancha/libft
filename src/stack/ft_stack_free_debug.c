/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free_debug.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:14:07 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 14:32:38 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/put.h"

static void     nbrput_ft(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else
    {
        if (n < 0)
        {
            n = -n;
            ft_putchar('-');
        }
        if (n >= 10)
            ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
}

void            ft_stack_free_debug(void)
{
    t_stacks    *stack;
    int         alloc;
    int         sys;

    stack = ft_stack_init();
    alloc = (int)stack->stack_size + 4;
    sys = (int)stack->sys + 13;
    ft_putstr("total heap usage: ");
    nbrput_ft(alloc);
    ft_putstr(" allocs, ");
    nbrput_ft(alloc);
    ft_putstr(" frees, ");
    nbrput_ft(sys);
    ft_putendl(" bytes allocated");
    ft_stack_free();
}
