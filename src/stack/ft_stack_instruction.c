/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:05:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 23:15:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

char            *ft_stack_instruction(int offset)
{
    t_stacks    *stack;
    t_pile      *pile;

    stack = ft_stack_init();
    pile = stack->pile;
    while (pile)
    {
        if (offset == pile->line)
            return (pile->instruction);
        pile = pile->next;
    }
    return (NULL);
}
