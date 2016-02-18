/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:29:14 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 08:44:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"

static void     *ft_alloc_delete(t_alloc *alloc)
{
    t_type      *type;
    t_stacks    *stack;

    stack = ft_stack_init();
    type = ft_vartype_get(alloc->type);
    if (alloc && alloc->content)
        type->del(&(alloc->content));
    ft_strdel(&(alloc->name));
    stack->elements -= 1;
    stack->free += 1;
    ft_memdel((void**)&(alloc));
    return (NULL);
}

void            *ft_stack_clean(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_alloc     *next;

    stack = ft_stack_init();
    if (!stack)
        return (NULL);
    alloc = stack->alloc;
    while (alloc)
    {
        next = alloc->next;
        if (alloc->type)
            ft_alloc_delete(alloc);
        else
            ft_memdel((void**)&(alloc));
        alloc = next;
    }
    stack->alloc = NULL;
    return (NULL);
}
