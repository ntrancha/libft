/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:29:12 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:19:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"

t_alloc         *ft_alloc_get(char *id)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    if (!(stack = ft_stack_init()))
        return (NULL);
    alloc = stack->alloc;
    while (alloc)
    {
        if (ft_strcmp(alloc->name, id) == 0)
            return (alloc);
        alloc = alloc->next;
    }
    return (NULL);
}
