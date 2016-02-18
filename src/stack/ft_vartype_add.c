/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartype_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:42:29 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 07:25:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static void ft_vartype_null(t_type *new, size_t n, void (*del)(void**))
{
    new->put = NULL;
    new->cpy = NULL;
    new->len = NULL;
    new->count = NULL;
    new->cmp = NULL;
    new->next = NULL;
    new->n_octet = n;
    new->del = del;
}

t_type      *ft_vartype_add(char *type, size_t n, void (*del)(void**))
{
    t_type  *new;
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();
    if (!type || !del || ft_vartype_get(type) != NULL)
        return (NULL);
    if (!(new = ft_memalloc(sizeof(t_type))))
        return (NULL);
    if (!(new->type = ft_strdup(type)))
    {
        ft_memdel((void**)&new);
        return (NULL);
    }
    ft_vartype_null(new, n, del);
    if (!(node = stack->types->next))
        stack->types->next = new;
    else
    {
        while (node->next)
            node = node->next;
        node->next = new;
    }
    return (stack->types);
}
