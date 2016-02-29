/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 21:40:38 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/29 21:48:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"

void            ft_syscmd_ret(int ret)
{
    t_stacks    *stack;
    t_pile      *pile;
    int         index;

    stack = ft_stack_init();
    if (stack)
    {
        pile = stack->pile;
        index = 1;
        while (pile)
        {
            if (index == stack->offset)
                pile->ret = ret;
            pile = pile->next;
            index++;
        }
    }
}
