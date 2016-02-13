/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:25:07 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/13 20:52:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/mem.h"

static void     *ft_alloc_delete(t_alloc *alloc)
{
    t_type      *type;
    t_stacks    *stack;

    stack = ft_stack_init();
    type = ft_vartype_get(alloc->type);
    type->del(&(alloc->content));
    if (alloc && alloc->name)
        ft_strdel(&(alloc->name));
    stack->elements -= 1;
    stack->free += 1;
    ft_memdel((void**)&(alloc));
    return (NULL);
}

t_stacks        *ft_alloc_del(char *id)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_alloc     *alloc_prev;
    t_alloc     *alloc_next;

    if (!(stack = ft_stack_init()) || !stack->alloc)
        return (NULL);    
    alloc = stack->alloc;
    alloc_next = alloc->next;
    alloc_prev = NULL;
    while (alloc)
    {
        alloc_next = alloc->next;
        if (alloc->name && !ft_strcmp(alloc->name, id))
        {
            ft_alloc_delete(alloc);
            if (alloc_prev == NULL)
                stack->alloc = alloc_next;
            else
                alloc_prev->next = alloc_next;
        }
        alloc_prev = alloc;
        alloc = alloc_next;
    }
    return (NULL);
}
