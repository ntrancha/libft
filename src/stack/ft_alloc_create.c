/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:41:35 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 00:09:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/mem.h"
#include "../../includes/convert.h"

static char     *ft_stack_randomid(void)
{
    static int  id_rand;

    id_rand++;
    return (ft_itoa(id_rand));
}

void        *ft_alloc_create(void *var, size_t len, char *id, char *type)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()) || !ft_vartype_get(type) || !len)
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (ft_alloc_get(id) != NULL || !(new = ft_memalloc(sizeof(t_alloc))))
        return (NULL);
    if (var)
        new->content = var;
    else if (!(new->content = ft_memalloc(len)))
        return (NULL);
    new->size = len;
    new->name = (id) ? ft_strdup(id) : ft_stack_randomid();
    new->type = ft_vartype_gettype(type);
    new->next = NULL;
    stack->elements += 1;
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}
