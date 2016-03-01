/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 12:19:52 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/01 12:24:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"

char            *ft_syscmd_offset(int offset)
{
    t_stacks    *stack;
    t_pile      *pile;
    int         count;

    count = 0;
    stack = ft_stack_init();
    pile = stack->pile;
    while (pile)
        if (offset == ++count)
            return (pile->instruction);
        else
            pile = pile->next;
    return (NULL);
}
