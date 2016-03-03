/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 20:54:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/03 20:56:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/sys.h"

char            *ft_stack_return(int offset, int ret)
{
    t_stacks    *stack;
    t_pile      *pile;
    int         count;

    count = 0;
    stack = ft_stack_init();
    pile = stack->pile;
    while (pile)
        if (offset == ++count)
            pile->ret = ret;
        else
            pile = pile->next;
    return (NULL);
}
