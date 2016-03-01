/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_condition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 11:35:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/01 12:00:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"

char            *ft_syscmd_condition(void)
{
    t_stacks    *stack;
    t_pile      *pile;
    int         test;
    int         offset;
    int         count;

    stack = ft_stack_init();
    if (!stack)
        return (NULL);
    pile = stack->pile;
    count = 0;
    offset = -1;
    while (pile && count++ <= stack->offset)
    {
        test = ft_syscmd_type(pile->instruction);
        offset = (test > 0 && test < 4) ? count : offset;
        pile = pile->next;
    }
    pile = stack->pile;
    while (pile && --offset > 0)
        pile = pile->next;
    if (pile)
        return (pile->instruction);
    return (NULL);
}

