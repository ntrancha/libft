/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_getvoid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:28:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:17:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_alloc         *ft_alloc_getvoid(void *var)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    if (!(stack = ft_stack_init()))
        return (NULL);
    alloc = stack->alloc;
    while (alloc)
    {
        if (var == alloc->content)
            return (alloc);
        alloc = alloc->next;
    }
    return (NULL);
}
